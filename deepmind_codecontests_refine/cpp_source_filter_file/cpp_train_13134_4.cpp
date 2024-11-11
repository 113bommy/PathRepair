#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long a, long long b, long long MOD) {
  long long ans = 1;
  while (b) {
    if (b % 2) ans = ans * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return ans;
}
const int N = 3e5 + 11;
map<int, int> vis;
int n, k, p, a[N];
long long ans;
int g(int x) {
  return (1ll * x * x % p * x % p * x % p - 1ll * k * x % p + 10 * p) % p;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> p >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    ans += vis[g(a[i])];
    vis[g(a[i])]++;
  }
  cout << ans << endl;
  return 0;
}
