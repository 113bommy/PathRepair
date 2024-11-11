#include <bits/stdc++.h>
using namespace std;
int read() {
  int res = 0, w = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') w = -1, c = getchar();
  while (isdigit(c)) res = (res << 1) + (res << 3) + c - '0', c = getchar();
  return res * w;
}
const int N = 2e5 + 10;
int n, q, a[N], l[N], r[N];
vector<int> g[N];
int solve(int l, int r) {
  int res = 0, last = l;
  sort(a + l, a + r + 1);
  for (int i = l + 1; i <= r; i++) {
    if (a[i] != a[i - 1]) {
      res = max(res, i - last);
      last = i;
    }
  }
  res = max(res, r + 1 - last);
  return r - l + 1 - res;
}
int main() {
  n = read(), q = read();
  int m = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    m = max(m, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!l[a[i]]) l[a[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    if (!r[a[i]]) r[a[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    if (l[i]) g[l[i]].push_back(r[i]);
  }
  int ans = 0;
  for (int l = 1, r = 0; l <= n; l = r + 1) {
    r = l;
    for (int tmp = l; tmp <= r; tmp++) {
      for (auto p : g[tmp]) {
        r = max(r, p);
      }
    }
    ans += solve(l, r);
  }
  cout << ans << endl;
  return 0;
}
