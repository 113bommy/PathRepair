#include <bits/stdc++.h>
const int maxn = 1e5;
int n;
char s[maxn + 5];
unsigned int f[maxn + 5];
signed main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  if (n & 1) {
    puts("1");
  } else {
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '?') {
        for (int j = i / 2; j >= 1; --j) {
          f[j] = f[j] * 25 + f[j - 1];
        }
        f[0] *= 25;
      }
    }
    std::cout << f[n / 2] << std::endl;
  }
}
