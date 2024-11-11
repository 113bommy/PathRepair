#include <bits/stdc++.h>
using namespace std;
const long long int Mod = 998244353;
const long long int mod = 1e9 + 7;
long long int Pow(long long int a, long long int b) {
  a = a % mod;
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return (res % mod);
}
long long int modInverse(long long int a, long long int m) {
  return Pow(a, m - 2);
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
const int N = 1e5 + 5;
int n, m, ans = 0;
int d[N], h[N];
bool fun(int i) {
  if (abs(d[i] - d[i + 1]) < abs(h[i] - h[i + 1])) return false;
  ans = max(ans, (h[i] + h[i + 1] + (d[i + 1] - d[i])) / 2);
  return 1;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> d[i] >> h[i];
  }
  ans = max(d[0] + h[0] - 1, n - d[m - 1] + h[m - 1]);
  for (int i = 0; i < m - 1; i++) {
    if (!fun(i)) {
      cout << "IMPOSSIBLE";
      return;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
