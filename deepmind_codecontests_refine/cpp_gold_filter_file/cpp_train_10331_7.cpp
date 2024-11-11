#include <bits/stdc++.h>
using namespace std;
template <typename T>
T getint() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') p = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * p;
}
template <typename T1, typename T2>
bool umin(T1 &x, const T2 &y) {
  if (x > y) return x = y, true;
  return false;
}
template <typename T1, typename T2>
bool umax(T1 &x, const T2 &y) {
  if (x < y) return x = y, true;
  return false;
}
const int maxn = (int)5e5 + 10;
const int inf = (int)1e9 + 5;
const int mod = 998244353;
const long long llinf = (long long)1e18 + 5;
const double pi = acos(-1.0);
mt19937 gen(123532);
int mul(int x, int y) { return 1LL * x * y % mod; }
void sub(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
  if (x >= mod) x -= mod;
}
int X[maxn];
int l[maxn], r[maxn], x[maxn];
int mxl[maxn];
int n, k, m;
int t[4 * maxn];
int add[maxn], f[maxn];
int solve() {
  memset(add, 0, sizeof add);
  for (int i = 0; i < m; ++i) {
    if (x[i]) {
      add[l[i]]++;
      add[r[i] + 1]--;
    }
  }
  for (int i = 1; i <= n; ++i) {
    add[i] += add[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    add[i] = (add[i] > 0);
  }
  memset(f, 0, sizeof f);
  f[0] = 1;
  int lastzero = -1;
  int sum = 1;
  for (int i = 1; i <= n; ++i) {
    if (add[i] == 0) {
      f[i] = sum;
      sub(sum, -sum);
    }
    if (mxl[i] > 0) {
      while (lastzero + 1 < mxl[i]) {
        ++lastzero;
        sub(sum, f[lastzero]);
        f[lastzero] = 0;
      }
    }
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k >> m;
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i] >> X[i];
  }
  int res = 1;
  for (int b = 0; b < k; ++b) {
    for (int i = 0; i < m; ++i) {
      x[i] = (X[i] >> b & 1);
    }
    memset(mxl, 0, sizeof mxl);
    for (int i = 0; i < m; ++i)
      if (x[i] == 0) {
        mxl[r[i]] = max(mxl[r[i]], l[i]);
      }
    res = mul(res, solve());
  }
  cout << res << endl;
  return 0;
}
