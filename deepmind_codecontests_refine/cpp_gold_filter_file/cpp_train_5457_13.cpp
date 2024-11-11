#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
void itval(istream_iterator<string> it) {}
template <typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  itval(++it, args...);
}
const long long int MOD = 1e9 + 7;
template <typename T>
inline void print(T x) {
  cout << x << "\n";
}
template <typename T>
inline void printvec(T x) {
  for (auto a : x) cout << a << ' ';
  cout << '\n';
}
struct custom {
  bool operator()(
      const pair<long long int, pair<long long int, long long int> > &p1,
      const pair<long long int, pair<long long int, long long int> > &p2)
      const {
    return p1.second.second < p2.second.second;
  }
};
long long int get_pow(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
const long long int N = 2e5 + 7, inf = 4e18;
int dp[5001][5001];
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (long long int i = (long long int)0; i < (long long int)(n); i++)
    cin >> v[i];
  for (long long int i = (long long int)0; i < (long long int)(n); i++) {
    for (int j = 0; j < m;) {
      if (v[i][j] == '0') {
        j++;
      } else {
        int k = j;
        while (k + 1 < m && v[i][k + 1] == '1') k++;
        for (int z = j; z <= k; z++) dp[z][k]++;
        j = k + 1;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = m - 1; j >= i; j--) {
      dp[i][j] += dp[i][j + 1];
    }
  }
  int ans = 0;
  for (long long int i = (long long int)0; i < (long long int)(m); i++) {
    for (long long int j = (long long int)i; j < (long long int)(m); j++) {
      ans = max(ans, (int)(j - i + 1) * dp[i][j]);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  clock_t z = clock();
  for (long long int tes = (long long int)0; tes < (long long int)(test);
       tes++) {
    solve();
  }
  fprintf(stderr, "Total Time:%.4f\n", (double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}
