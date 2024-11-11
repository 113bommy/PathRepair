#include <bits/stdc++.h>
const int maxn = 400010, mo = 1000000007, rev = 500000004;
int d, range, n;
char s[maxn], ans[maxn];
long long prev[maxn], next[maxn], e[maxn];
bool ok(int l, int r) {
  int length = r - l + 1, ml, mr;
  l++;
  r++;
  if (length & 1)
    ml = mr = l + length / 2;
  else
    ml = l + length / 2 - 1, mr = ml + 1;
  long long x = ((prev[ml] - prev[l - 1] * e[ml - l + 1]) % mo + mo) % mo,
            y = ((next[r] - next[mr - 1]) % mo + mo) % mo;
  x = (x * e[mr - 1]) % mo;
  return x == y;
}
bool dfs(int x, bool flag) {
  if (x == n && !flag) return false;
  if (x == n) return ans[n] = '\0', true;
  char start = flag ? 'a' : s[x];
  for (ans[x] = start; ans[x] <= 'z'; ans[x]++) {
    prev[x + 1] = (prev[x] * 37 + ans[x]) % mo;
    next[x + 1] = (next[x] + ans[x] * e[x]) % mo;
    if ((x + 1 >= d && ok(x - d + 1, x)) || (x >= d && ok(x - d, x))) continue;
    if (dfs(x + 1, flag || ans[x] > start)) return true;
  }
  return false;
}
int main() {
  scanf("%d", &d);
  range = (d + 1) / 2;
  scanf("%s", s);
  n = strlen(s);
  e[0] = 1;
  for (int i = 1; i <= n; i++) e[i] = e[i - 1] * 37;
  if (dfs(0, false))
    printf("%s", ans);
  else
    printf("Impossible");
}
