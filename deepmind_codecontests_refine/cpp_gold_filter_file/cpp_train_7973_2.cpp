#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(const vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << '\n';
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());
vector<long long> xx = {1, 0, -1, 0, 1, -1, 1, -1};
vector<long long> yy = {0, 1, 0, -1, -1, -1, 1, 1};
string dir = "RDLU";
string travel = "ENWS";
const long long N = 1e5 + 50, oo = 3e18 + 500;
const long long mod = 998244353;
const long long M2 = 1000000093, x2 = 27162;
const long long M1 = 1000000087, x1 = 241;
const long double eps = 1e-18, PI = 2 * acos(0.0);
long long n, m, k;
long long cnt = 0;
long long lg = 18;
vector<vector<long long> > g;
vector<vector<long long> > rg;
vector<long long> visit;
long long a[4][N];
long long b[4][N];
vector<long long> check(vector<long long> &n) {
  long long j, z, k;
  j = z = k = 0;
  vector<long long> ret(5, oo);
  for (long long i = 0; i < n[0]; i++) {
    while (j + 1 < n[1] && b[1][j] < b[0][i]) {
      j++;
    }
    while (z + 1 < n[2] && b[2][z] < b[0][i]) {
      z++;
    }
    while (k + 1 < n[3] && (b[3][k] < b[1][j] || b[3][k] < b[2][z])) {
      k++;
    }
    if (b[3][k] >= b[1][j] && b[3][k] >= b[2][z] && b[1][j] >= b[0][i] &&
        b[2][z] >= b[0][i]) {
      vector<long long> kek = {b[3][k] - b[0][i], b[0][i], b[1][j], b[2][z],
                               b[3][k]};
      ret = min(ret, kek);
      ;
    }
  }
  return ret;
}
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long k;
  cin >> k;
  while (k--) {
    cin >> n;
    long long D = 9 + 8 * (n - 1);
    long long y = (-3 + sqrt(D)) / 2;
    long long ans = 0;
    for (long long yy = max(y - 100, 0ll); yy <= y + 100 && yy <= n - 1; yy++) {
      ans = max(ans, n - 1 - yy + min(yy * (yy + 1) / 2, n - 1 - yy));
      ;
    }
    cout << ans << '\n';
  }
}
