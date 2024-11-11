#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
bool isprime(long long n) {
  if (n % 2 == 0) {
    return false;
  }
  for (auto i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long digitsum(long long n) {
  long long sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n, a, b, c, d;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c >> d;
    if (a <= b)
      cout << b << endl;
    else if (a > b && c <= d)
      cout << -1 << endl;
    else
      cout << b + c * ((a - b) / (c - d)) + c * (int)((a - b) % (c - d) > 0)
           << endl;
  }
}
