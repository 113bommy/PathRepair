#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const long long int N = 1e3 + 5;
long long int mod = 1e9 + 7;
long long int dx[4] = {0, 0, +1, -1};
long long int dy[4] = {+1, -1, 0, 0};
long long int c[N][N], pw[N];
void solve() {
  for (long long int i = 0; i < N; i++) {
    for (long long int j = 0; j < i + 1; j++) {
      if (j == 0 || j == i)
        c[i][j] = 1;
      else
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      c[i][j] %= mod;
    }
  }
  pw[0] = 1;
  pw[1] = 2;
  for (long long int i = 2; i < N; i++) {
    pw[i] = 2 * pw[i - 1];
    pw[i] %= mod;
  }
  long long int n, m;
  cin >> n >> m;
  vector<long long int> v(m, 0);
  for (long long int i = 0; i < m; i++) cin >> v[i];
  sort((v).begin(), (v).end());
  long long int temp = 0, cnt = 0, ans = 1;
  for (long long int i = 0; i < (long long int)v.size(); i++) {
    cnt = v[i] - 1;
    if (i > 0) {
      cnt -= v[i - 1];
      ans = ans * pw[cnt - 1];
      ans %= mod;
    }
    temp += cnt;
    ans = ans * c[temp][cnt];
    ans %= mod;
  }
  temp += n - (v[(long long int)v.size() - 1]);
  ans = ans * c[temp][n - v[(long long int)v.size() - 1]];
  ans %= mod;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  while (t--) solve();
  return 0;
}
