#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long st = n;
  long long firstdig;
  long long numdigits;
  while (n != 0) {
    numdigits++;
    firstdig = n % 10;
    n = n / 10;
  }
  if (firstdig == 9) {
    long long nextnum = pow(10LL, numdigits, 1e18);
    long long ans = abs(nextnum - st);
    cout << ans;
  } else {
    long long nextnum = (firstdig + 1) * pow(10LL, numdigits - 1, 1e18);
    long long ans = abs(nextnum - st);
    cout << ans;
  }
  return 0;
}
