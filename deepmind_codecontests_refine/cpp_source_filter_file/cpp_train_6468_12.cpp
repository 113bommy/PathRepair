#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:128777216")
template <typename T>
T fac(T a) {
  return a ? a * fac(a - 1) : 1;
}
template <typename T>
T power(T a, int p) {
  return !p ? 1 : (p & 1 ? a * power(a, p - 1) : power(a * a, p >> 1));
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T lcm(T a, T b) {
  return b / gcd(a, b) * a;
}
template <typename T>
T next() {
  T _;
  cin >> _;
  return _;
}
template <>
int next<int>() {
  int _;
  scanf("%d", &_);
  return _;
}
template <>
double next<double>() {
  double _;
  scanf("%lf", &_);
  return _;
}
template <>
long long next<long long>() {
  long long _;
  scanf("%lld", &_);
  return _;
}
template <typename E>
vector<E> next(int n) {
  vector<E> res(n);
  for (int i = 0; i < n; i++) res[i] = next<E>();
  return res;
}
template <class C, class E>
int count(const C &c, const E &e) {
  return count(c.begin(), c.end(), e);
}
template <class E>
bool has(const vector<E> &c, const E &e) {
  return find(c.begin(), c.end(), e) != c.end();
}
template <class E>
int find(const vector<E> &c, const E &e) {
  return find(c.begin(), c.end(), e) - c.begin();
}
template <class E>
bool binary_has(const vector<E> &c, const E &e) {
  return binary_search(c.begin(), c.end(), e);
}
template <class E>
int binary_find(const vector<E> &c, const E &e) {
  return lower_bound(c.begin(), c.end(), e) - c.begin();
}
template <typename T>
T dist2(T i1, T j1, T i2, T j2) {
  return (i1 - i2) * (i1 - i2) + (j1 - j2) * (j1 - j2);
}
bool ok(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}
const double EPS = 1e-9;
const double PI = acos(-1);
bool LE(double a, double b) { return b - a > -EPS; }
bool BE(double a, double b) { return a - b > -EPS; }
bool EQ(double a, double b) { return fabs(a - b) < EPS; }
bool LESS(double a, double b) { return b - a > EPS; }
bool BIGG(double a, double b) { return a - b > EPS; }
int randomInt(int from, int to) { return from + rand() % (to - from + 1); }
long long wws[128];
char str[128];
long long dp[101][101][101][2];
long long dp2[101][101];
long long solve(int i, int j, int k, int c);
long long solve(int i, int j) {
  if (i == j) return wws[1];
  if (dp2[i][j] == -1) {
    dp2[i][j] = -(1LL << 50);
    for (int k = 1; k < (j - i); k++) {
      dp2[i][j] = max(dp2[i][j], wws[k + 1] + solve(i + 1, j, k, str[i] - '0'));
    }
  }
  return dp2[i][j];
}
long long solve(int i, int j, int k, int c) {
  if (k == 0) {
    return solve(i, j);
  }
  if (k > j - i + 1) return -(1LL << 50);
  if (i == j) {
    if (str[i] - '0' == c)
      return 0;
    else
      return -(1LL << 50);
  }
  if (dp[i][j][k][c] == -1) {
    if (str[i] - '0' == c && k > 0)
      dp[i][j][k][c] = solve(i + 1, j, k - 1, c);
    else
      dp[i][j][k][c] = -(1LL << 50);
    for (int ii = i; ii <= j; ii++) {
      dp[i][j][k][c] =
          max(dp[i][j][k][c], solve(i, ii) + solve(ii + 1, j, k, c));
    }
  }
  return dp[i][j][k][c];
}
int main() {
  int n = next<int>();
  scanf("%s", str);
  for (int i = 0; i < n; i++) wws[i + 1] = next<int>();
  for (int i = 0; i < 101; i++)
    for (int j = 0; j < 101; j++)
      for (int k = 0; k < 101; k++) dp[i][j][k][0] = dp[i][j][k][1] = -1;
  for (int i = 0; i < 101; i++)
    for (int j = 0; j < 101; j++) dp2[i][j] = -1;
  cout << solve(0, n - 1) << endl;
  return 0;
}
