#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 0x7f7f7f7f;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
char s[2 * N];
int main() {
  int n, t;
  scanf("%d", &n);
  t = n;
  long long ans = 0;
  for (int i = 2; i * i <= t; i++) {
    while (t / i > 1 && t % i == 0) {
      ans += t / i;
      t /= i;
    }
  }
  ans += n + 1;
  printf("%lld\n", ans);
  return 0;
}
