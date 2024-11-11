#include <bits/stdc++.h>
using namespace std;
void get(int &v) {
  char c;
  while ((c = getchar()) != EOF && isdigit(c) == 0)
    ;
  v = c - '0';
  while ((c = getchar()) != EOF && isdigit(c))
    v = (v << 3) + (v << 1) + c - '0';
  return;
}
int pow_mod(long long a, int x) {
  int ans = 1;
  while (x) {
    if (x & 1) ans = ans * a % 1000000007;
    a = a * a % 1000000007;
    x >>= 1;
  }
  return ans;
}
int a[200000 + 80];
int main() {
  int n, i, ans = 0;
  long long f = 1, tmp;
  get(n);
  for (i = 1; i <= n; i++) get(a[i]);
  switch (n % 4) {
    case 0:
      for (i = 1; i <= (n >> 1); i++) {
        ans = (ans + (a[(i << 1) - 1] - a[(i << 1)]) * f) % 1000000007;
        f = f * ((n >> 1) - i) % 1000000007 * pow_mod(i, 1000000007 - 2) %
            1000000007;
      }
      break;
    case 1:
      for (i = 0; i <= (n >> 1); i++) {
        ans = (ans + a[(i << 1) + 1] * f) % 1000000007;
        f = f * ((n >> 1) - i) % 1000000007 * pow_mod(i + 1, 1000000007 - 2) %
            1000000007;
      }
      break;
    case 2:
      for (i = 1; i <= (n >> 1); i++) {
        ans = (ans + (a[(i << 1) - 1] + a[(i << 1)]) * f) % 1000000007;
        f = f * ((n >> 1) - i) % 1000000007 * pow_mod(i, 1000000007 - 2) %
            1000000007;
      }
      break;
    case 3:
      ans = a[1];
      for (i = 1; i <= (n >> 1); i++) {
        ans = (ans + ((a[i << 1] * f) << 1)) % 1000000007;
        tmp = f;
        f = f * ((n >> 1) - i) % 1000000007 * pow_mod(i, 1000000007 - 2) %
            1000000007;
        ans = (ans + (f - tmp) * a[(i << 1) + 1]) % 1000000007;
      }
      break;
  }
  printf("%d", (ans + 1000000007) % 1000000007);
  return 0;
}
