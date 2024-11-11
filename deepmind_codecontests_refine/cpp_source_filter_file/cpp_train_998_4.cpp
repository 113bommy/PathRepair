#include <bits/stdc++.h>
using namespace std;
int T;
long long a, b, x;
int Calc(int x, int a) {
  int cnt = 0;
  for (; a % x == 0; a /= x, cnt++)
    ;
  return cnt;
}
bool judge(int x, int a, int b) {
  int p = Calc(x, a), q = Calc(x, b);
  return p + p >= q || q + q >= p;
}
int main() {
  for (cin >> T; T--;) {
    scanf("%lld%lld", &a, &b), x = a * b;
    long long p = pow(x, 1. / 3);
    if ((p + 1) * (p + 1) * (p + 1) == x) p = p + 1;
    if (p * p * p != x) {
      puts("No");
      continue;
    }
    bool res = 1;
    for (long long i = 2; i * i <= p; i++)
      if (p % i == 0) {
        for (; p % i == 0; p /= i)
          ;
        if (!judge(i, a, b)) {
          res = 0;
          break;
        }
      }
    if (res && p > 1 && !judge(p, a, b)) res = 0;
    puts(res ? "Yes" : "No");
  }
}
