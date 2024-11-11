#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a, id(n + 1), res(n + 1);
  a.push_back(-1);
  for (int i = 0, j; i < n; i++) {
    cin >> j;
    if (a.back() != j) a.push_back(j);
  }
  int m = a.size() - 1;
  queue<array<int, 3>> q;
  vector<int> pr(m + 1), nx(m + 1, m + 1);
  for (int i = 1; i <= m; i++) {
    nx[id[a[i]]] = i;
    id[a[i]] = i;
    q.push({i, i, 1});
  }
  fill(id.begin(), id.end(), 0);
  for (int i = m; i > 0; i--) {
    pr[id[a[i]]] = i;
    id[a[i]] = i;
  }
  res[1] = m;
  for (int i = 2; i <= n; i++) {
    queue<array<int, 3>> p;
    while (!q.empty()) {
      auto [xl, xr, xc] = q.front();
      q.pop();
      int tm = xc;
      bool fnd = false;
      while (!q.empty()) {
        auto &[l, r, c] = q.front();
        for (; l <= r; l++) {
          if (pr[l] < xl) {
            if (xc == i) {
              fnd = true;
              p.push({xl, xr, xc});
              break;
            }
            xc++, xr = l;
          }
          if (r < nx[l]) c--;
        }
        if (fnd) break;
        if (l > r || c <= 0) q.pop();
      }
      if (!fnd) p.push({xl, m, xc});
    }
    res[i] = p.size();
    q.swap(p);
  }
  for (int i = 1; i <= n; i++) cout << res[i] << " \n"[i == n];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
