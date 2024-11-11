#include <bits/stdc++.h>
using namespace std;
long long a, b, p, n, ans;
inline long long power(int a, int b) {
  if (b == 0) return 1LL;
  long long k = power(a, b / 2);
  k = (k * k) % p;
  if (b % 2) return (k * a) % p;
  return k;
}
inline long long inv(long long n) { return power(n, p - 2); }
int main() {
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> p >> n;
  for (int j = 1; j <= p - 1; j++) {
    long long y = (b * inv(power(a, j))) % p;
    long long f = (p - 1) * ((j - y + p) % p) + j;
    if (f > n) continue;
    ans += (n - f + 1) / (p * (p - 1));
  }
  cout << ans << endl;
  return 0;
}
