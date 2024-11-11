#include <bits/stdc++.h>
using namespace std;
int n, x, y, tot;
long long f[300010];
char s[300010];
int main() {
  scanf("%d%d%d", &n, &x, &y);
  scanf("%s", s + 1);
  for (int l = 1, r = 1; l <= n; l = r + 1) {
    tot++;
    for (r = l; r < n && s[l] == s[r + 1]; r++)
      ;
    if (s[l] == '1')
      f[tot] = f[tot - 1];
    else {
      f[tot] = f[tot - 1] + y;
      if (tot >= 3) f[tot] = min(f[tot], f[tot - 2] + x);
    }
  }
  printf("%lld\n", f[tot]);
}
