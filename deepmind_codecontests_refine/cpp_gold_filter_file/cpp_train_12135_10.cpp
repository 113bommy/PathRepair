#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int pct(int x) { return __builtin_popcount(x); }
int bit(int x) { return 31 - __builtin_clz(x); }
int cdiv(int a, int b) { return a / b + !(a < 0 || a % b == 0); }
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
const int maxn = 1e5 * 3 + 20;
int n, _, q, k;
int m;
int mat[25][25];
void solve() {
  cin >> n >> m;
  for (signed i = 1; i <= n; i++)
    for (signed j = 1; j <= m; j++) cin >> mat[i][j];
  vector<int> p;
  p.emplace_back(0);
  for (signed i = 1; i <= m; i++) p.emplace_back(i);
  for (signed i = 1; i <= m; i++) {
    for (signed j = i; j <= m; j++) {
      vector<int> tmp = p;
      swap(tmp[i], tmp[j]);
      42;
      bool valid = true;
      for (signed ii = 1; ii <= n; ii++) {
        int cnt = 0;
        for (signed jj = 1; jj <= m; jj++) {
          if (mat[ii][jj] != tmp[jj]) cnt++;
        }
        if (cnt > 2) valid = false;
      }
      if (valid) {
        cout << "YES";
        exit(0);
      }
    }
  }
  bool valid = true;
  for (signed i = 1; i <= n; i++) {
    int cnt = 0;
    for (signed j = 1; j <= m; j++) {
      if (mat[i][j] != p[j]) cnt++;
    }
    if (cnt > 2) valid = false;
  }
  if (valid) {
    cout << "YES";
    exit(0);
  }
  cout << "NO" << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
