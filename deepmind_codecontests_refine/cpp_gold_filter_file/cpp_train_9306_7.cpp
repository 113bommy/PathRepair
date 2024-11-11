#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a > b) {
    int t;
    t = a;
    a = b;
    b = t;
  }
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
bool prime(long long int n) {
  long long int i, f = 0;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) f++;
  }
  if (f == 0)
    return 1;
  else
    return 0;
}
int main() {
  long long int n, d, i, j;
  cin >> n >> d;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int f = 0;
  sort(a, a + n);
  for (long long int i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j != i) {
        if (abs(a[j] - a[i]) <= d) f++;
      }
    }
  }
  cout << f << '\n';
}
