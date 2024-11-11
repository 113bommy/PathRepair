#include <bits/stdc++.h>
using namespace std;
const int size = 100001;
long long int a[size], p[size];
long long int gcd(long long int a, long long int b) {
  return (b == 0 ? a : gcd(b, a % b));
}
int main() {
  int n;
  long long int q = 0;
  cin >> n;
  long long int sum = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n + 1);
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
  for (int i = n; i > 0; i--) q += (a[i] * (i - 1) - p[i - 1]);
  sum = p[n] + q;
  long long int g = gcd(sum, n);
  cout << sum / g << ' ' << n / g;
}
