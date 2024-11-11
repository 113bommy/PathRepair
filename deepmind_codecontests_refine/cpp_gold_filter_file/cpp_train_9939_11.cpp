#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 100005;
inline void read(int &x) {
  char ch;
  int t = 0;
  x = 0;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') t = 1;
  for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - 48, ch = getchar())
    ;
  if (t) x = -x;
}
int a[N], b[N];
vector<int> v[N];
int main() {
  int n, m, i, j, k, t, l, r, x, y, s;
  long long ans;
  while (~scanf("%d", &n)) {
    memset(v, 0, sizeof v);
    for (i = 0; i < n; i++) read(a[i]);
    for (i = 0; i < n; i++) v[a[i]].push_back(i);
    for (s = m = 0, i = 1; i <= n; i++) {
      if ((v[i].size())) b[m++] = i;
      if ((v[i].size()) & 1) {
        if (s) break;
        s = i;
      }
    }
    if (i <= n) {
      printf("0\n");
      continue;
    }
    for (k = 0; k < n / 2; k++)
      if (a[k] != a[n - k - 1]) break;
    if (k == n / 2) {
      printf("%lld\n", (long long)n * (n + 1) >> 1);
      continue;
    }
    for (y = n + 1, i = x = 0; i < m; i++) {
      t = b[i];
      if (!((v[t].size()) & 1))
        l = (v[t].size()) / 2 - 1, r = l + 1;
      else
        l = r = (v[t].size()) / 2;
      while (l >= 0 && v[t][l] + v[t][r] == n - 1) l--, r++;
      if (l < 0) continue;
      x = max(x, v[t][l]);
      y = min(y, v[t][r]);
    }
    l = n - k - 1 - x;
    r = y - k;
    ans = (long long)l * (k + 1) + (long long)r * (k + 1) +
          (long long)(k + 1) * (k + 1);
    printf("%lld\n", ans);
  }
  return 0;
}
