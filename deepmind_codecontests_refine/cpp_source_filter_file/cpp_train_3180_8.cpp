#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return a > val ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
struct GridModule {
  int n, m;
  vector<vector<int> > a;
  vector<vector<int> > row, col;
  vector<vector<int> > dig[2];
  void init(vector<vector<int> >& x, int k) {
    a = x;
    n = a.size();
    if (n)
      m = a[0].size();
    else
      m = 0;
    row.resize(n);
    for (int i = 0; i < n; i++) {
      row[i].clear();
      int tot = 0;
      for (int j = 0; j < m; j++) {
        tot += a[i][j] == k;
        row[i].push_back(tot);
      }
    }
    col.resize(m);
    for (int j = 0; j < m; j++) {
      col[j].clear();
      int tot = 0;
      for (int i = 0; i < n; i++) {
        tot += a[i][j] == k;
        col[j].push_back(tot);
      }
    }
    dig[0].resize(n + m - 1);
    for (int i = 0; i < m; i++) {
      dig[0][i].clear();
      int tot = 0;
      for (int j = 0; j < min(i + 1, n); j++) {
        tot += a[j][i - j] == k;
        dig[0][i].push_back(tot);
      }
    }
    for (int i = 1; i < n; i++) {
      dig[0][i + m - 1].clear();
      int tot = 0;
      for (int j = 0; j < min(n - i, m); j++) {
        tot += a[i + j][m - j - 1] == k;
        dig[0][i + m - 1].push_back(tot);
      }
    }
    dig[1].resize(n + m - 1);
    for (int i = m - 1; i >= 0; i--) {
      dig[1][m - i - 1].clear();
      int tot = 0;
      for (int j = 0; j < min(m - i, n); j++) {
        tot += a[j][i + j] == k;
        dig[1][m - i - 1].push_back(tot);
      }
    }
    for (int i = 1; i < n; i++) {
      dig[1][i + m - 1].clear();
      int tot = 0;
      for (int j = 0; j < min(n - i, m); j++) {
        tot += a[i + j][j] == k;
        dig[1][i + m - 1].push_back(tot);
      }
    }
  }
  int rowsum(int x, int y, int z) {
    if (y > z) swap(y, z);
    return row[x][z] - (y ? row[x][y - 1] : 0);
  }
  int colsum(int x, int y, int z) {
    if (y > z) swap(y, z);
    return col[x][z] - (y ? col[x][y - 1] : 0);
  }
  int diagonal(int x, int y, int z, int t) {
    if (x > z) {
      swap(x, z);
      swap(y, t);
    }
    if (x + y == z + t) {
      int u = x + y;
      if (u >= m) {
        x = m - y - 1;
        z = m - t - 1;
      }
      return dig[0][u][z] - (x ? dig[0][u][x - 1] : 0);
    } else if (x - y == z - t) {
      int u = m + x - y - 1;
      if (u >= m) {
        x = y;
        z = t;
      }
      return dig[1][u][z] - (x ? dig[1][u][x - 1] : 0);
    }
    return 0;
  }
} gr[4];
const int maxn = 1010;
int n;
char s[maxn];
int row[maxn];
int col[maxn];
long double p2[maxn];
long double p3[maxn];
void solve() {
  p2[0] = p3[0] = 1;
  for (int i = (1); i < (maxn); i++)
    p2[i] = p2[i - 1] * 2, p3[i] = p3[i - 1] * 3;
  scanf("%d", &n);
  vector<vector<int> > a(n, vector<int>(n, 0));
  for (int i = (0); i < (n); i++) {
    scanf("%s", s);
    for (int j = (0); j < (n); j++) a[i][j] = s[j] - '0';
  }
  for (int i = (0); i < (4); i++) gr[i].init(a, i);
  pair<long double, int> ans;
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (n); j++)
      if (a[i][j]) {
        int lo = 0, hi = i;
        chkmin(hi, n - i - 1);
        chkmin(hi, j);
        chkmin(hi, n - j - 1);
        while (lo < hi) {
          int mi = lo + hi + 1 >> 1;
          if (!gr[0].rowsum(i, j - mi, j + mi) &&
              !gr[0].colsum(j, i - mi, i + mi)) {
            lo = mi;
          } else {
            hi = mi - 1;
          }
        }
        int n2 =
            gr[2].rowsum(i, j - lo, j + lo) + gr[2].colsum(j, i - lo, i + lo);
        int n3 =
            gr[3].rowsum(i, j - lo, j + lo) + gr[3].colsum(j, i - lo, i + lo);
        chkmax(ans,
               make_pair(p2[n2] * p3[n3] / a[i][j],
                         mult(fpow(2, n2), mult(fpow(3, n3), inv(a[i][j])))));
        lo = 0, hi = i;
        chkmin(hi, n - i - 1);
        chkmin(hi, j);
        chkmin(hi, n - j - 1);
        while (lo < hi) {
          int mi = lo + hi + 1 >> 1;
          if (!gr[0].diagonal(i - mi, j - mi, i + mi, j + mi) &&
              !gr[0].diagonal(i - mi, j + mi, i + mi, j - mi)) {
            lo = mi;
          } else {
            hi = mi - 1;
          }
        }
        n2 = gr[2].diagonal(i - lo, j - lo, i + lo, j + lo) +
             gr[2].diagonal(i - lo, j + lo, i + lo, j - lo);
        n3 = gr[3].diagonal(i - lo, j - lo, i + lo, j + lo) +
             gr[3].diagonal(i - lo, j + lo, i + lo, j - lo);
        chkmax(ans,
               make_pair(p2[n2] * p3[n3] / a[i][j],
                         mult(fpow(2, n2), mult(fpow(3, n3), inv(a[i][j])))));
      }
  printf("%d\n", ans.second);
}
int main() {
  solve();
  return 0;
}
