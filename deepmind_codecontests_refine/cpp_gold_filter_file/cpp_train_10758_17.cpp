#include <bits/stdc++.h>
const int mn = 401000, q = 131, mo = 2147483647;
int l, n, i, j;
int x[mn], y[mn], g[mn];
char s[mn], a[mn];
bool sol;
bool cmp(int l, int r) {
  if (l > r) return 1;
  int t1 = ((long long)x[r] * g[r - l] - (long long)x[r - l] * g[r]) % mo;
  t1 = ((long long)t1 + mo) % mo;
  int t2 = ((long long)y[r] - y[r - l] + mo) % mo;
  return t1 != t2;
}
void dfs(int r, bool v) {
  if (sol) return;
  if (r > n) {
    sol = 1;
    return;
  }
  char i;
  for (i = v ? s[r] : 'a'; i <= 'z'; ++i) {
    x[r] = ((long long)x[r - 1] * q + i - 96) % mo;
    y[r] = ((long long)(i - 96) * g[r - 1] + y[r - 1]) % mo;
    if (cmp(l, r) && cmp(l + 1, r)) {
      a[r] = i;
      dfs(r + 1, v && i == s[r]);
      if (sol) return;
    }
  }
}
int main() {
  scanf("%d", &l);
  scanf("%s", s + 1);
  n = strlen(s + 1);
  g[0] = 1;
  for (i = 1; i <= n; ++i) g[i] = (long long)g[i - 1] * q % mo;
  for (i = n; s[i] == 'z' && i; --i)
    ;
  if (i == 0) {
    puts("Impossible");
    return 0;
  };
  ++s[i];
  for (j = i + 1; j <= n; ++j) s[j] = 'a';
  dfs(1, 1);
  if (sol)
    puts(a + 1);
  else
    puts("Impossible");
  return 0;
}
