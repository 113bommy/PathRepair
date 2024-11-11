#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000007;
long long const md = 998244353;
long long mypow(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ifstream in("txt.in");
ofstream out("txt.out");
int f[105];
int main() {
  cout << fixed << setprecision(12);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  long long n, x, y;
  cin >> n >> x >> y;
  for (int i = 1; i <= n; ++i) {
    cin >> f[i];
  }
  sort(f + 1, f + n + 1);
  if (x > y) return cout << n, 0;
  int u = 0;
  for (int i = 1; i <= n; ++i) {
    if (x >= f[i]) u = i;
  }
  cout << (u + 1) / 2 << '\n';
  return 0;
}
