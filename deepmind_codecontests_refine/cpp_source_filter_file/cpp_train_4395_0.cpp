#include <bits/stdc++.h>
const int MAXN = 2000 + 5;
const int ha = 1e9 + 7;
inline int add(int x, int y) {
  (x += y);
  if (x >= ha) x -= ha;
  return x;
}
int pw[MAXN];
int f[MAXN][MAXN];
char str[MAXN];
int sm[MAXN], n;
int main() {
  pw[0] = 1;
  for (int i = 1; i <= MAXN - 1; ++i) pw[i] = add(pw[i - 1], pw[i - 1]);
  scanf("%s", str + 1);
  n = strlen(str + 1);
  for (int i = 1; i <= n; ++i) sm[i] = sm[i - 1] + (str[i] == '?');
  for (int len = 2; len <= n; ++len) {
    for (int l = 1; l <= n - len + 1; ++l) {
      int r = l + len - 1;
      if (str[l] != '(') f[l][r] = add(f[l][r], f[l + 1][r]);
      if (str[r] != ')') f[l][r] = add(f[l][r], f[l][r - 1]);
      if (str[l] != '(' && str[r] != ')')
        f[l][r] = add(f[l][r], ha - f[l + 1][r - 1]);
      if (str[l] != ')' && str[r] != '(')
        f[l][r] = add(f[l][r],
                      add(f[l + 1][r - 1], pw[std::max(0, sm[r - 1] - sm[l])]));
    }
  }
  printf("%d\n", f[1][n]);
  return 0;
}
