#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T fetch() {
  T ret;
  cin >> ret;
  return ret;
}
template <typename T>
inline vector<T> fetch_vec(long long sz) {
  vector<T> ret(sz);
  for (auto& it : ret) cin >> it;
  return ret;
}
template <typename T>
inline void makeUnique(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
template <typename T>
inline T max_(T a, T b) {
  if (a > b) return a;
  return b;
}
template <typename T>
inline T min_(T a, T b) {
  if (a < b) return a;
  return b;
}
void file() {}
void Match() {}
long long dp[40][2][2][2], a[40], b[40];
long long dfs(long long pos, bool limit1, bool limit2, bool flag) {
  if (!pos) return flag;
  if (dp[pos][limit1][limit2][flag] != -1) return dp[pos][limit1][limit2][flag];
  long long maxn1 = (limit1 ? a[pos] : 1);
  long long maxn2 = (limit2 ? b[pos] : 1);
  long long ans = 0;
  for (long long i = 0; i <= maxn1; i++)
    for (long long j = 0; j <= maxn2; j++)
      ans += dfs(pos - 1, limit1 && i == maxn1, limit2 && j == maxn2,
                 flag && (i + j <= 1));
  return dp[pos][limit1][limit2][flag] = ans;
}
long long query(long long l, long long r) {
  if (l < 0 || r < 0) return 0;
  memset(dp, -1, sizeof(dp));
  ;
  memset(a, 0, sizeof(a));
  ;
  memset(b, 0, sizeof(b));
  ;
  while (l) a[++a[0]] = l & 1, l >>= 1;
  while (r) b[++b[0]] = r & 1, r >>= 1;
  return dfs(max(a[0], b[0]), true, true, true);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  file();
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    cout << query(r, r) - query(r, l - 1) * 2 + query(l - 1, l - 1) << "\n";
  }
  return 0;
}
