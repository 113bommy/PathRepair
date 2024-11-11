#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long a, b;
  cin >> a >> b;
  if (gcd(a, b) > 1)
    printf("Impossible\n");
  else {
    while (a && b) {
      if (a > b) {
        printf("%dA", (a - 1) / b);
        a %= b;
      } else {
        printf("%dB", (b - 1) / a);
        b %= a;
      }
    }
    puts("");
  }
  return 0;
}
