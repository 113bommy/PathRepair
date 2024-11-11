#include <bits/stdc++.h>
using namespace std;
clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
template <typename T>
void _F(const char *name, T arg1) {
  cerr << name << " = " << arg1 << '\n';
}
template <typename T, typename... Args>
void _F(const char *names, T arg1, Args... args) {
  const char *name = strchr(names, ',');
  cerr.write(names, name - names) << " = " << arg1 << '\n';
  _F(name + 2, args...);
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &q) {
  in >> q.first >> q.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &q) {
  out << q.first << " " << q.second;
  return out;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> p1, pair<T1, T2> p2) {
  return {p1.first + p2.first, p1.second + p2.second};
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> p1, pair<T1, T2> p2) {
  return {p1.first - p2.first, p1.second - p2.second};
}
const long long N = 101;
long long dp[2][N][N][N], ans[N][N];
long long a[N], n;
string s;
long long DP(long long f, long long l, long long r, long long cnt);
long long Ans(long long l, long long r);
long long Ans(long long l, long long r) {
  if (r < l) return 0;
  if (r == l) return (ans[l][r] = a[1]);
  if (ans[l][r] != -1) return ans[l][r];
  long long tmp = 0;
  for (long long cnt = 1; cnt <= r - l + 1; cnt++) {
    tmp = max(tmp, DP(0, l, r, cnt) + a[cnt]);
    tmp = max(tmp, DP(1, l, r, cnt) + a[cnt]);
  }
  return (ans[l][r] = tmp);
}
long long DP(long long f, long long l, long long r, long long cnt) {
  if ((r - l + 1) < cnt) return -(long long)(1e18 + 1);
  if (cnt == 0) return Ans(l, r);
  if (dp[f][l][r][cnt] != -1) return dp[f][l][r][cnt];
  long long tmp = -(long long)(1e18 + 1);
  for (long long i = l; i <= r; i++) {
    if (s[i - 1] - '0' == f)
      tmp = max(tmp, Ans(l, i - 1) + DP(f, i + 1, r, cnt - 1));
  }
  return (dp[f][l][r][cnt] = tmp);
}
void solve() {
  cin >> n;
  cin >> s;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  memset(ans, -1, sizeof(ans));
  cout << Ans(1, n) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  start = clock();
  cout << fixed << setprecision(20);
  for (long long i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
