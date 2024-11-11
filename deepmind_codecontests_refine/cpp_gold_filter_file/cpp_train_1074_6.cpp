#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return (a < b); }
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long int n, i;
  double sum = 0.0, p, t = 3.1415926536;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i = i + 1) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (n % 2 != 0) {
    for (i = n - 1; i >= 1; i = i - 2) {
      sum = sum + t * (((a[i]) * a[i]) - ((a[i - 1]) * a[i - 1]));
    }
    p = t * a[0] * a[0];
    cout << sum + p;
  }
  if (n % 2 == 0) {
    for (i = n - 1; i >= 0; i = i - 2) {
      sum = sum + t * (((a[i]) * a[i]) - ((a[i - 1]) * a[i - 1]));
    }
    cout << sum;
  }
  return 0;
}
