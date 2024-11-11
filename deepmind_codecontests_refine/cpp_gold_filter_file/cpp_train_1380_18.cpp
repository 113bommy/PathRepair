#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 13);
int n, s[N], f[N], g[N];
long long w[13];
int main() {
  cin >> n;
  for (int i = 0; i < (1 << 13); i++)
    if (__builtin_popcount(i) == 6) {
      f[++f[0]] = i;
      if (f[0] <= n) g[i] = f[0];
    }
  for (int i = 0; i <= 12; i++) {
    s[0] = 0;
    for (int z = 0; z < (1 << 13); z++)
      if (g[z] && (z & (1 << i))) s[++s[0]] = g[z];
    if (s[0] > 0) {
      printf("? %d ", s[0]);
      for (int z = 1; z <= s[0]; z++) printf("%d ", s[z]);
      puts("");
      fflush(stdout), cin >> w[i];
    }
  }
  printf("! ");
  for (int i = 1; i <= n; i++) {
    int x = f[i];
    long long ans = 0;
    for (int z = 0; z <= 12; z++)
      if (!(x & (1 << z))) ans |= w[z];
    printf("%lld ", ans);
  }
  return 0;
}
