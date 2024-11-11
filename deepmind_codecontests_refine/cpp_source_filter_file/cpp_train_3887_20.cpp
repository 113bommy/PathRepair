#include <bits/stdc++.h>
template <class T>
inline T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (!b) return a;
  return __gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / __gcd(a, b)) * b;
}
template <class T>
inline T ncr(T n, T r) {
  return n * (n - 1) / r;
}
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n];
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    sum += ar[i];
  }
  sort(ar, ar + n);
  long long int take = 0;
  for (int i = n - 1, j = 1; i >= 0; i--, j++) {
    take += ar[i];
    if (take > sum / 2) {
      cout << i + 1 << endl;
      break;
    }
  }
  return 0;
}
