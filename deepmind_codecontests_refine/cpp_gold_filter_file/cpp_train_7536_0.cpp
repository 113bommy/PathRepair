#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 11;
int a[N];
long long gcd(long long a, long long b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0, dif = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    sum += a[i];
  }
  sort(a, a + n);
  long long last = 0;
  for (int i = 0; i < n - 1; i++) {
    last += (a[i + 1] - a[i]) * (i + 1);
    dif += 2 * last;
  }
  sum = (sum + dif);
  long long g = gcd(sum, n);
  sum /= g;
  n /= g;
  printf("%I64d %d\n", sum, n);
}
