#include <bits/stdc++.h>
using namespace std;
int setBit(int n, int r) { return n | (1 << r); }
int resetBit(int n, int r) { return n & ~(1 << r); }
bool checkBit(int n, int r) { return bool(n & (1 << r)); }
template <typename T>
T mod(T a, T b = 1000000007) {
  return (a % b) >= 0 ? (a % b) : (a % b) + b;
}
template <typename T>
T bigmod(T p, T e, T M) {
  T ret = 1;
  while (e > 0) {
    if (e % 2) ret = (ret * p) % M;
    p = (p * p) % M;
    e /= 2;
  }
  return ret;
}
template <typename T>
T power(T x, T y) {
  T ans = 1;
  while (y > 0) {
    if (y % 2) ans *= x;
    x *= x;
    y /= 2;
  }
  return ans;
}
template <typename T>
T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
void read(T &result) {
  bool sgn = false;
  result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    sgn = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (sgn) result = -result;
}
int n, m, we;
int w[(int)1e3 + 5], b[(int)1e3 + 5], tw[(int)1e3 + 5], tb[(int)1e3 + 5];
int par[(int)1e3 + 5], com[(int)1e3 + 5];
int dp[(int)1e3 + 5][(int)1e3 + 5];
int cnt;
vector<int> v[(int)1e3 + 5];
int root(int r) { return r == par[r] ? r : par[r] = root(par[r]); }
int go(int ii, int jj) {
  if (ii == cnt) return 0;
  int &ret = dp[ii][jj];
  if (ret != -1) return ret;
  ret = go(ii + 1, jj);
  int r = com[ii];
  if (tw[r] + jj <= we) {
    ret = max(ret, tb[r] + go(ii + 1, jj + tw[r]));
  }
  for (int to : v[r]) {
    if (w[to] + jj <= we) ret = max(ret, b[to] + go(ii + 1, jj + w[to]));
  }
  return ret;
}
int main() {
  read(n);
  read(m);
  read(we);
  for (int i = 1; i <= n; i++) read(w[i]);
  for (int i = 1; i <= n; i++) read(b[i]);
  for (int i = 1; i <= n; i++) {
    tw[i] = w[i];
    tb[i] = b[i];
  }
  for (int i = 1; i <= n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    read(x);
    read(y);
    x = root(x);
    y = root(y);
    if (x != y) {
      par[y] = x;
      tw[x] += w[y];
      tb[x] += b[y];
    }
  }
  for (int i = 1; i <= n; i++) {
    v[root(i)].push_back(i);
  }
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (par[i] == i) {
      com[cnt++] = i;
    }
  }
  memset(dp, -1, sizeof(dp));
  printf("%d", go(0, 0));
}
