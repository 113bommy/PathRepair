#include <bits/stdc++.h>
using namespace std;
template <class T>
bool rmn(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool rmx(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const long long INFLL = 0x7f7f7f7f7f7f7f7f, MOD = 1e9 + 7;
const long long INF = 0x7f7f7f7f;
vector<vector<pair<long long, long long>>> adj;
vector<long long> vis, color;
long long dx8[] = {0, 1, 1, 1, 0, -1, -1, -1},
          dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx4[] = {0, 1, 0, -1},
          dy4[] = {1, 0, -1, 0};
inline long long mexp(long long x, long long n, long long m = MOD) {
  long long res = 1;
  x %= m;
  while (n) {
    if (n & 1) res = (res * x) % m;
    n >>= 1;
    x = (x * x) % m;
  }
  return res;
}
inline long long gcd(long long a, long long b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  while (a > 0 && b > 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cerr << fixed;
  cout << setprecision(10);
  cerr << setprecision(3);
  mt19937 genr(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long n;
  cin >> n;
  const long long N = 20, NN = 1 << N;
  vector<vector<long long>> col(N);
  vector<long long> dp(NN, INFLL);
  for (long long i = 0; i < n; ++i) {
    long long c;
    cin >> c;
    c--;
    col[c].push_back(i);
  }
  vector<vector<long long>> cnt(NN, vector<long long>(N, 0));
  for (long long i = 0; i < N; ++i)
    for (long long j = 0; j < N; ++j) {
      if (i == j) continue;
      for (auto idx : col[i]) {
        cnt[i][j] +=
            upper_bound(col[j].begin(), col[j].end(), idx) - col[j].begin();
      }
    }
  dp[0] = 0;
  for (long long mask = 0; mask < NN; ++mask) {
    for (long long b = 0, bv = 1; b < N; b++, bv <<= 1) {
      if ((bv & mask) == 1) continue;
      long long sum = 0;
      for (long long p = 0; p < N; ++p) {
        if ((1 << p) & mask) sum += cnt[b][p];
      }
      dp[mask | bv] = min(dp[mask | bv], dp[mask] + sum);
    }
  }
  cout << dp[NN - 1] << '\n';
  return 0;
}
