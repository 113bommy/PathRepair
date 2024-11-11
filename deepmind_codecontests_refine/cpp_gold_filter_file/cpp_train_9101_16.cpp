#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void put(T&&... args) {
  ((cout << args << " "), ...);
}
template <typename... T>
void putl(T&&... args) {
  ((cout << args << " "), ...);
  cout << '\n';
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << "=" << a << ", ";
  err(++it, args...);
}
const long long inf = INT_MAX;
const long double ep = 0.0000001;
const long double pi = acos(-1.0);
const long long md = 1000000007;
long long mat[1005][1005];
long long a1[1005][1005], a2[1005][1005];
long long b1[1005][1005], b2[1005][1005];
void solve() {
  long long n, m;
  see(n, m);
  for (long long i = 1; i < n + 1; ++i) {
    for (long long j = 1; j < m + 1; ++j) {
      see(mat[i][j]);
    }
  }
  for (long long i = 1; i < n + 1; ++i)
    for (long long j = 1; j < m + 1; ++j)
      a1[i][j] = mat[i][j] + max(a1[i - 1][j], a1[i][j - 1]);
  for (long long i = n; i > 0; --i)
    for (long long j = m; j > 0; --j)
      a2[i][j] = mat[i][j] + max(a2[i + 1][j], a2[i][j + 1]);
  for (long long i = n; i > 0; --i)
    for (long long j = 1; j < m + 1; ++j)
      b1[i][j] = mat[i][j] + max(b1[i + 1][j], b1[i][j - 1]);
  for (long long i = 1; i < n + 1; ++i)
    for (long long j = m; j > 0; --j)
      b2[i][j] = mat[i][j] + max(b2[i - 1][j], b2[i][j + 1]);
  long long s = 0;
  for (long long i = 2; i < n; ++i) {
    for (long long j = 2; j < m; ++j) {
      s = max({a1[i - 1][j] + a2[i + 1][j] + b1[i][j - 1] + b2[i][j + 1],
               a1[i][j - 1] + a2[i][j + 1] + b2[i - 1][j] + b1[i + 1][j], s});
    }
  }
  put(s);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
}
