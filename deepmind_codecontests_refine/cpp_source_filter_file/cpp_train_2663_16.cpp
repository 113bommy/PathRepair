#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int mod = 1000000007;
char s[N];
int c[N], f[N], g[N];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 0; i < n; i++) scanf("%d", c + i);
  f[0] = 1;
  g[0] = 0;
  int ma = 1;
  for (int i = 1; i <= n; i++) {
    s[i] -= 'a';
    int mi = n;
    g[i] = i;
    for (int j = i; j > 0; j--) {
      mi = min(mi, c[s[j]]);
      if (i - j + 1 > mi) break;
      ma = max(ma, i - j + 1);
      f[i] = (f[i] + f[j - 1]) % mod;
      g[i] = min(g[i], g[j - 1] + 1);
    }
  }
  printf("%d\n%d\n%d", f[n], ma, g[n]);
}
