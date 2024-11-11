#include <bits/stdc++.h>
const long double PI = acos(-1);
const long double eps = 0.0000000001;
const long long INF = 0x3fffffffffffffff;
const long long MOD = 1000000007;
const long double log23 = log2(3);
long long n;
long long power(long long A, long long B) {
  long long res = 1;
  while (B) {
    if (B & 1) res = res * A % MOD;
    A = A * A % MOD;
    B >>= 1;
  }
  return res;
}
struct node {
  long long num[4];
  node() { num[0] = num[1] = num[2] = num[3] = 0; }
  node(char c) { num[0] = num[1] = num[2] = num[3] = 0, num[c - '0'] = 1; }
  long long &operator[](const long long &X) { return num[X]; }
  const long long &operator[](const long long &X) const { return num[X]; }
  friend node operator+(const node &A, const node &B) {
    node res;
    for (long long i = 0; i != 4; ++i) res[i] = A[i] + B[i];
    return res;
  }
  friend node operator-(const node &A, const node &B) {
    node res;
    for (long long i = 0; i != 4; ++i) res[i] = A[i] - B[i];
    return res;
  }
  node &operator+=(const node &X) {
    for (long long i = 0; i != 4; ++i) num[i] += X[i];
    return *this;
  }
  friend bool operator<(const node &A, const node &B) {
    if (A.num[0]) return true;
    if (B.num[0]) return false;
    return A.num[2] + A.num[3] * log23 < B.num[2] + B.num[3] * log23;
  }
  long long asint() const {
    return num[0] ? 0 : power(2, num[2]) * power(3, num[3]) % MOD;
  }
};
std::vector<node> suml[2005], sumc[2005];
node ans = '0';
char c[2005][2005], d[2005][2005], e[2005][2005];
long long len[2005][2005];
template <class T>
void min(T X, long long x, long long y, long long vx, long long vy) {
  x += vx;
  y += vy;
  for (long long i = 1; x >= 0 && x < n && y >= 0 && y < n && X[x][y] != '0';
       ++i, x += vx, y += vy)
    len[x][y] = std::min(len[x][y], i);
}
template <class T>
void solve(T x) {
  for (long long i = 0; i != n; ++i) suml[i] = std::vector<node>(1);
  for (long long i = 0; i != n; ++i) sumc[i] = std::vector<node>(1);
  for (long long i = 0; i != n; ++i)
    for (long long j = 0; j != n; ++j) {
      suml[i].push_back(suml[i].back() + x[i][j]);
      sumc[j].push_back(sumc[j].back() + x[i][j]);
    }
  memset(len, 0x3f, sizeof(len));
  for (long long i = -1; i <= n; ++i)
    for (long long j = -1; j <= n; ++j)
      if (i == -1 || j == -1 || i == n || j == n || x[i][j] == '0') {
        min(x, i, j, +1, 0);
        min(x, i, j, -1, 0);
        min(x, i, j, 0, -1);
        min(x, i, j, 0, +1);
      }
  for (long long i = 0; i != n; ++i)
    for (long long j = 0; j != n; ++j)
      if (x[i][j] != '0')
        ans =
            std::max(ans, suml[i][j + len[i][j]] - suml[i][j - len[i][j] + 1] +
                              sumc[j][i + len[i][j]] -
                              sumc[j][i - len[i][j] + 1] - x[i][j]);
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  memset(d, '0', sizeof(d));
  memset(e, '0', sizeof(e));
  for (long long i = 0; i != n; ++i)
    for (long long j = 0; j != n; ++j) {
      std::cin >> c[i][j];
      if ((i + j) & 1)
        d[(i + j) / 2][(i - j + n) / 2] = c[i][j];
      else
        e[(i + j) / 2][(i - j + n) / 2] = c[i][j];
    }
  solve(c);
  solve(d);
  solve(e);
  std::cout << ans.asint() << std::endl;
  return 0;
}
