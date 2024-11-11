#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
long long int power(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long int t = power(a, b / 2, m) % m;
  t = (t * t) % m;
  if (b & 1) t = ((t % m) * (a % m)) % m;
  return t;
}
long long int modInverse(long long int a, long long int m) {
  return power(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, a, b, c;
  cin >> n >> a >> b >> c;
  if (n == 1) {
    cout << "0";
    return 0;
  }
  if (a <= b && a <= c) {
    cout << a * (n - 1);
  } else if (b <= a && b <= c) {
    cout << b * (n - 1);
  } else {
    cout << c * (n - 2) + min(a, b);
  }
  return 0;
}
