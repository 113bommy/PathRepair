#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int n, m;
long long f[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  f[1] = 2, f[2] = 4;
  cin >> n >> m;
  for (int i = 3; i <= max(n, m); ++i) f[i] = f[i - 1] % mod + f[i - 2] % mod;
  cout << f[n] + f[m] - 2 << '\n';
  return 0;
}
