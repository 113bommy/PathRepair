#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = 2 * acos((long double)0);
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
void setmin(int& a, int val) {
  if (a > val) a = val;
}
void setmax(int& a, int val) {
  if (a < val) a = val;
}
const int maxn = 3010;
int n, m;
char s[maxn];
int a[maxn][maxn];
int l[maxn][maxn];
int r[maxn][maxn];
long long ans;
const int MAXX = 6010;
const int MAXY = 6010;
int fen[MAXX][MAXY];
void update(int x, int y, int val) {
  while (x < MAXX) {
    int y1 = y;
    while (y1 < MAXY) {
      fen[x][y1] += val;
      y1 += y1 & -y1;
    }
    x += x & -x;
  }
}
int query(int x, int y) {
  int res = 0;
  while (x) {
    int y1 = y;
    while (y1) {
      res += fen[x][y1];
      y1 -= y1 & -y1;
    }
    x -= x & -x;
  }
  return res;
}
void go1() {
  for (int i = (0); i < (n); i++) {
    int cur = -1;
    for (int j = (0); j < (i + 2); j++) {
      if (j == i + 1 || !a[j][i - j]) {
        if (~cur) {
          vector<pair<int, int> > his;
          for (int k = (cur); k < (j); k++) {
            ans += query(MAXX - k - 1, MAXY + r[k][i - k] - k - 1 - 3000);
            update(MAXX - l[k][i - k] - k, MAXY - k - 3000, 1);
            his.push_back(make_pair(MAXX - l[k][i - k] - k, MAXY - k - 3000));
          }
          for (int k = (0); k < (int((his).size())); k++) {
            int u = his[k].first;
            int v = his[k].second;
            update(u, v, -1);
          }
          cur = -1;
        }
      } else {
        if (!~cur) {
          cur = j;
        }
      }
    }
  }
}
void go2() {
  for (int i = (1); i < (n); i++) {
    int cur = -1;
    for (int j = (0); j < (n - i + 1); j++) {
      if (j == n - i || !a[i + j][n - 1 - j]) {
        if (~cur) {
          vector<pair<int, int> > his;
          for (int k = (cur); k < (j); k++) {
            ans += query(MAXX - (i + k) - 1,
                         MAXY + r[i + k][n - 1 - k] - k - 1 - 3000);
            update(MAXX - l[i + k][n - 1 - k] - (i + k), MAXY - k - 3000, 1);
            his.push_back(make_pair(MAXX - l[i + k][n - 1 - k] - (i + k),
                                    MAXY - k - 3000));
          }
          for (int k = (0); k < (int((his).size())); k++) {
            int u = his[k].first;
            int v = his[k].second;
            update(u, v, -1);
          }
          cur = -1;
        }
      } else {
        if (!~cur) {
          cur = j;
        }
      }
    }
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (n); i++) {
    scanf("%s", s);
    for (int j = (0); j < (m); j++) {
      a[i][j] = s[j] == 'z';
      ans += a[i][j];
    }
  }
  n = max(n, m);
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (n); j++) {
      if (a[i][j]) {
        if (j)
          l[i][j] = l[i][j - 1] + 1;
        else
          l[i][j] = 1;
      }
    }
    for (int j = (n)-1; j >= (0); j--) {
      if (a[i][j]) {
        r[i][j] = r[i][j + 1] + 1;
      }
    }
  }
  go1();
  go2();
  cout << ans;
}
int main() {
  solve();
  return 0;
}
