#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
bool IsPowerOfTwo(long long int x) { return (x != 0) && ((x & (x - 1)) == 0); }
long long int poer(long long int a, long long int b) {
  long long int rs = 1;
  while (b > 0) {
    if (b & 1) rs *= a;
    a *= a;
    b /= 2;
  }
  return rs;
}
long long int mod_poer(long long int a, long long int b, long long int mo) {
  long long int rs = 1;
  while (b > 0) {
    if (b & 1) rs = (rs * a) % mo;
    a = (a * a) % mo;
    b /= 2;
  }
  return rs % mo;
}
long long int d, x, y;
void ext_euclid(long long int a, long long int b) {
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
  } else {
    ext_euclid(b, a % b);
    long long int temp = x;
    x = y;
    y = temp - (a / b) * y;
  }
}
long long int mod_inverse1(long long int a, long long int m) {
  ext_euclid(a, m);
  return (x % m + m) % m;
}
long long int mod_inverse2(long long int a, long long int m) {
  return mod_poer(a, m - 2, m);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int a[100005];
long long int i, n, m, k;
long long int dp[100005];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    long long int x;
    cin >> x, dp[x] = dp[x - 1] + 1;
  }
  long long int maxi = INT_MIN;
  for (i = 0; i < n; i++) maxi = max(maxi, dp[i]);
  cout << n - maxi << endl;
  return 0;
}
