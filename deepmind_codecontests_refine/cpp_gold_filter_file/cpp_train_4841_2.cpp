#include <bits/stdc++.h>
using namespace std;
const char eol = '\n';
int n, m;
vector<vector<int> > a;
vector<vector<int> > pos;
vector<vector<int> > neg;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m;
  a = vector<vector<int> >(n + 1);
  pos = vector<vector<int> >(m + 1);
  neg = vector<vector<int> >(m + 1);
  for (int i = 1; i < (n + 1); ++i) {
    int k;
    cin >> k;
    a[i] = vector<int>(k);
    for (int j = 0; j < (k); ++j) {
      cin >> a[i][j];
      if (a[i][j] < 0) {
        neg[-a[i][j]].push_back(i);
      } else {
        pos[a[i][j]].push_back(i);
      }
    }
  }
  vector<bool> sat(n + 1);
  vector<int> res(m + 1, -1);
  for (int i = 1; i < (m + 1); ++i) {
    if (pos[i].empty()) {
      res[i] = 0;
      for (int u : neg[i]) sat[u] = true;
    } else if (neg[i].empty()) {
      res[i] = 1;
      for (int u : pos[i]) sat[u] = true;
    }
  }
  vector<int> d(n + 1);
  priority_queue<pair<int, int> > q;
  for (int i = 1; i < (n + 1); ++i) {
    if (sat[i]) continue;
    d[i] = int(a[i].size());
    q.emplace(-d[i], i);
  }
  while (!q.empty()) {
    int t = -q.top().first;
    int i = q.top().second;
    q.pop();
    if (sat[i] || d[i] != t) continue;
    int r = -1;
    int w = -1;
    for (int u : a[i]) {
      if (res[abs(u)] == -1) {
        int other = u < 0 ? pos[abs(u)][0] : neg[u][0];
        if (r == -1 || d[other] > w) {
          r = abs(u);
          w = d[other];
        }
      }
    }
    if (r == -1) {
      cout << "NO" << eol;
      return 0;
    }
    sat[i] = true;
    if (pos[r][0] == i) {
      int j = neg[r][0];
      res[r] = 1;
      d[j] -= 1;
      q.emplace(-d[j], j);
    } else {
      int j = pos[r][0];
      res[r] = 0;
      d[j] -= 1;
      q.emplace(-d[j], j);
    }
  }
  for (int i = 1; i < (n + 1); ++i) {
    if (!sat[i]) {
      cout << "NO" << eol;
      return 0;
    }
  }
  cout << "YES" << eol;
  for (int i = 1; i < (m + 1); ++i) {
    if (res[i] == -1)
      cout << 0;
    else
      cout << res[i];
  }
  cout << eol;
  return 0;
}
