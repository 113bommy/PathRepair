#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const long long MOD2 = 998244353;
const long long N = 1000 * 1000 + 10;
const long long N2 = 70;
const long double PI = 3.14159265358979323846;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long p = LLONG_MAX) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
void solve() {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  pair<long long, long long> p[n];
  for (long long i = 0; i < n; i++) {
    cin >> p[i].first;
    p[i].second = i;
  }
  sort(p, p + n);
  long long a[n];
  for (long long i = 0; i < n; i++) {
    a[i] = p[i].second;
  }
  vector<vector<long long>> q;
  long long vis[N] = {0};
  for (long long i = 0; i < n; i++) {
    if (vis[i]) continue;
    long long pos = i;
    vector<long long> cycle;
    while (!vis[pos]) {
      vis[pos] = 1;
      cycle.push_back(pos + 1);
      pos = a[pos];
    }
    q.push_back(cycle);
  }
  cout << q.size() << "\n";
  for (long long i = 0; i < q.size(); i++) {
    cout << q[i].size() << " ";
    for (long long j = 0; j < q[i].size(); j++) {
      cout << q[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
