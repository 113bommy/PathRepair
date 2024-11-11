#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int g, r;
  cin >> g >> r;
  vector<vector<bool> > was(m, vector<bool>(g + 1, 0));
  vector<vector<int> > wait(m, vector<int>(g + 1, 0));
  was[0][0] = 1;
  deque<pair<int, int> > dq;
  dq.push_front(make_pair(0, 0));
  int i;
  long long t, ans = -1, pot, lim, newt, mod;
  while (!dq.empty()) {
    i = dq.front().first;
    t = dq.front().second;
    dq.pop_front();
    if (i == m - 1) {
      pot = t + wait[i][t] * (g + r);
      if (ans == -1 || pot < ans) ans = pot;
      continue;
    }
    if (t == g) {
      if (was[i][0] == false) {
        wait[i][0] = wait[i][t] + 1;
        was[i][0] = true;
        dq.push_back(make_pair(i, 0));
      }
    }
    if (i > 0) {
      newt = t + a[i] - a[i - 1];
      if (g >= newt && was[i - 1][newt] == false) {
        wait[i - 1][newt] = wait[i][t];
        was[i - 1][newt] = true;
        dq.push_front(make_pair(i - 1, newt));
      }
    }
    if (i < m - 1) {
      newt = t + a[i + 1] - a[i];
      if (g >= newt && was[i + 1][mod] == false) {
        wait[i + 1][newt] = wait[i][t];
        was[i + 1][newt] = true;
        dq.push_front(make_pair(i + 1, newt));
      }
    }
  }
  cout << ans;
  return 0;
}
