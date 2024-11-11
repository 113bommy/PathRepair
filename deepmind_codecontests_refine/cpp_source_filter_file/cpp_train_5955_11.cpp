#include <bits/stdc++.h>
#pragma 03
using namespace std;
long long f(long long n, long long k) {
  if (n == 0) return k * (k + 1) / 2;
  long long p = f(n / k, k), s = n % k, l = k * k + 1, pivot;
  if (p % l == 0)
    pivot = l;
  else
    pivot = p % l;
  if (s * k < pivot - k)
    return (n / k) * l * k + k * k * s + k * (k + 1) / 2;
  else if (s * k < pivot)
    return (n / k) * l * k + k * k * s + k * (k + 1) / 2 + k + s * k - pivot +
           1;
  else
    return (n / k) * l * k + k * k * s + (k + 1) * (k + 2) / 2 - 1;
}
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long sgm = (n - 1) / (k * k + 1);
    long long last = f(sgm, k);
    if (last < n)
      cout << (n - sgm - 1) + (n - sgm - 2) / k << endl;
    else if (last == n)
      cout << (sgm + 1) * (k + 1) << endl;
    else
      cout << (n - sgm) + (n - sgm - 1) / k << endl;
  }
}
