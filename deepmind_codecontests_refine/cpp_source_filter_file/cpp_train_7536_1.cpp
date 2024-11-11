#include <bits/stdc++.h>
using namespace std;
int x[100010];
long long gcd(long long A, long long B) {
  if (B == 0) return A;
  return gcd(B, A % B);
}
int main() {
  int n;
  long long sum1 = 0, sum2 = 0, sumBefore = 0, sumtot = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x[i]);
    sum1 += x[i];
  }
  sort(x + 1, x + n + 1);
  long long val = n - 1;
  long long i = 0;
  while (val > 0) {
    sum2 += val * (x[n - i - 1] - x[i]);
    i++;
    val -= 2;
  }
  sumtot = sum1 + 2 * sum2;
  long long _gcd = gcd(sumtot, n);
  cout << sumtot / _gcd << " " << n / _gcd;
  return 0;
}
