#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 1e3 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
const double Pi = acos(-1.0);
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long qpow(long long n, long long m) {
  long long ret = 1;
  while (m) {
    if (m & 1) ret = ret * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return ret;
}
long long getinv(long long a) { return qpow(a, mod - 2); }
int n, m;
string s[N];
int ans[N][N];
void main0() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    s[i] = "$" + s[i];
    int cur = 1;
    for (int j = 1; j <= m; ++j) {
      cur ^= 5;
      if (s[i][j] == '.') ans[i][j] = cur;
      if ((s[i - 1][j] == 'X') && (s[i][j] == 'X')) cur ^= 5;
    }
  }
  int succ = 1;
  for (int i = 2; i <= n - 1; ++i) {
    for (int j = 2; j <= m - 1; ++j)
      if (s[i][j] == 'X') {
        int cnt = 0;
        for (int d = 0; d <= 3; ++d) {
          int xt = i + dx[d];
          int yt = j + dy[d];
          cnt += (s[xt][yt] == '.');
          ans[i][j] += (s[xt][yt] == '.') * ans[xt][yt];
        }
        if (cnt & 1) succ = 0;
      }
  }
  if (succ) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cout << ans[i][j] << ' ';
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}
