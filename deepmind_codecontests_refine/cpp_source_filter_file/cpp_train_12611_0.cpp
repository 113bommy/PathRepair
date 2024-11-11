#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> cand(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    cand[x - 1].push_back(y - 1);
  }
  for (int i = 0; i < n; i++) {
    if (cand[i].empty()) {
      continue;
    }
    int nearest;
    int bestD;
    for (int j = 0; j < (int)cand[i].size(); j++) {
      int d = cand[i][j] > i ? abs(i - cand[i][j])
                             : abs(n - 1 - i) + abs(cand[i][j] - 0);
      if (j == 0 || d < bestD) {
        bestD = d;
        nearest = j;
      }
    }
    swap(cand[i][nearest], cand[i][0]);
  }
  vector<int> p(n);
  for (int start = 0; start < n; start++) {
    queue<int> q;
    int v = start;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      p[i] = (int)cand[i].size() - 1;
    }
    while (cnt != m) {
      if (p[v] >= 0) {
        q.push(cand[v][p[v]]);
        p[v]--;
      }
      int sz = (int)q.size();
      for (int i = 0; i < sz; i++) {
        int c = q.front();
        q.pop();
        if (c == v) {
          cnt++;
        } else {
          q.push(c);
        }
      }
      if (cnt == m) {
        break;
      }
      ans++;
      v = (v + 1) % n;
    }
    cout << ans << ' ';
  }
}
