#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
const int MOD = 1e12 + 7;
const int MAX = 1e6 + 2;
const int INF = 0x3f3f3f3f;
using namespace std;
long long a[100001], n, m, ans = 0;
long long siabus(long long p) { return (n + p) / m; }
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    a[(i * i) % m] += siabus(i);
  }
  for (int i = 0; i < m; ++i) {
    ans += a[i] * a[(m - i) % m];
  }
  cout << ans << endl;
  return 0;
}
