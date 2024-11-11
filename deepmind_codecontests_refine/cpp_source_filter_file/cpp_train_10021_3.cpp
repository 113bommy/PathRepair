#include <bits/stdc++.h>
const int maxn = 1e6 + 5, mod = 1e9 + 7;
char s[maxn];
int n, L, R, trans[maxn][2], len[maxn], fir[maxn], f[maxn], ans;
void plus(int &x, int v) { x += v, (x >= mod ? x -= mod : 0); }
int main() {
  scanf("%s", s + 1), n = strlen(s + 1);
  while (s[n] == '0') --n, ++R;
  if (n == 0) return printf("%d\n", R), 0;
  while (s[L + 1] == '0') ++L;
  for (int i = 1; i <= n - L; ++i) s[i] = s[i + L];
  n -= L;
  int lst = n + 1;
  for (int i = n; i; --i) trans[i][1] = lst, (s[i] == '1' ? lst = i : 0);
  for (int i = 1; i <= n; ++i) len[i] = s[i] == '1' ? 0 : len[i - 1] + 1;
  for (int i = 1; i <= n; ++i) fir[i] = n + 1;
  for (int i = n; i; --i) trans[i][0] = fir[len[i] + 1], fir[len[i]] = i;
  f[1] = 1;
  for (int i = 1; i <= n; ++i) {
    if (trans[i][0] <= n) plus(f[trans[i][0]], f[i]);
    if (trans[i][1] <= n) plus(f[trans[i][1]], f[i]);
  }
  for (int i = 1; i <= n; ++i)
    if (s[i] == '1') plus(ans, f[i]);
  printf("%d\n", 1ll * ans * (L + 1) * (R + 1) % mod);
  return 0;
}
