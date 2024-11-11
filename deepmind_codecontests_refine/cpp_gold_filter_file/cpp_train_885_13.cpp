#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
  long long d = b - c;
  long long ans = 0;
  if (a <= d) {
    ans = n / a;
    printf("%I64d\n", ans);
  } else {
    long long tmp = n;
    while (n >= b) {
      ans++;
      ans += (n - b) / (b - c);
      n = ((n - b) % (b - c)) + b - ((b - c));
    }
    ans += n / a;
    printf("%I64d\n", ans);
  }
}
