#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const int ULTRA = 1e14;
const int PROMAX = 1e6 + 5;
const int PRO = 1e5 + 5;
long long dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
long long dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};
inline long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
inline long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n + 1], b[n + 1], c[n + 1];
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    c[a[i]] = i;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
  }
  map<long long, long long> d;
  for (long long i = 1; i <= n; i++) {
    d[(b[i] - c[b[i]] + n) % n] += 1;
  }
  long long res = 0;
  for (auto x : d) {
    res = max(res, x.second);
  }
  cout << res << endl;
}
