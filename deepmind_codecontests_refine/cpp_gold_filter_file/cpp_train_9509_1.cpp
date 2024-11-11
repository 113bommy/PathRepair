#include <bits/stdc++.h>
using namespace std;
const int N = 1010, mod = 1000000007;
char s[N], c[N];
int main() {
  scanf("%s%s", s, c);
  int K, n;
  scanf("%d", &K);
  if (K == 0) {
    printf("%d\n", strcmp(s, c) == 0);
    return 0;
  }
  n = strlen(s);
  long long a = 0, b = 1, f = -1;
  K--;
  while (K--) {
    a = b * (n - 1);
    b = a + f;
    f *= -1;
    a %= mod;
    b %= mod;
  }
  int ans = 0;
  if (strcmp(s, c) == 0) ans += a;
  for (int i = 1; i < n; i++) {
    rotate(s, s + 1, s + n);
    if (strcmp(s, c) == 0) ans += b;
    if (ans >= mod) ans -= mod;
  }
  printf("%d\n", ans);
  scanf(" ");
}
