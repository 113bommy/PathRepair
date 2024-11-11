#include <bits/stdc++.h>
using namespace std;
void solve();
long long fact[200001];
long long inf = 1e18;
long long z = 1e9 + 7;
vector<int> dr{0, 0, -1, 1}, dc{-1, 1, 0, 0};
long long n, m;
bool valid(long long x, long long y) {
  if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1)
    return 1;
  else
    return 0;
}
long long gdp(long long a, long long b) { return (a - (a % b)); }
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long c = power(a, b / 2, p);
  if (b % 2 == 0)
    return ((c * c) % p);
  else
    return ((((c * c) % p) * a) % p);
}
long long inverse(long long a, long long n) { return power(a, n - 2, n); }
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long ncr(long long n, long long r) {
  if (n < r || (n < 0) || (r < 0)) return 0;
  return ((((fact[n] * inverse(fact[r], z)) % z) * inverse(fact[n - r], z)) %
          z);
}
long long mods(long long n) {
  if (n > 0)
    return n;
  else
    return n * -1;
}
bool isprime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool b1 = 0;
vector<long long> adj[100001];
bool vis[100001] = {0};
long long color[100001];
bool ok = 1;
long long endi;
long long parent[100001] = {0};
long long flag;
long long st;
vector<long long> prms;
bool fun(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.second < p2.second;
}
int main() {
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long x, y;
    for (long long i = 0; i < n - 1; i++) {
      if (s[i + 1] >= s[i]) {
        continue;
      } else {
        cout << "YES\n";
        cout << i << " " << i + 1 << "\n";
        return 0;
      }
    }
    cout << "NO";
  }
}
