#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
long long lowbit(long long x) { return x & (-x); }
long long prime(long long x) {
  if (x <= 1) return false;
  for (int i = 2; i <= int(sqrt(x)); i++) {
    if (x % i == 0) return false;
  }
  return true;
}
bool cmp(long long a, long long b) { return a > b; }
long long gcd(long long a, long long b) {
  long long r;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
inline int readint() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
inline long long readll() {
  long long f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
void fl(string name) {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1},
          dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
long long n, k, dp[210][210][210];
string a, b;
int main() {
  cin >> n >> k >> a >> b;
  a = ' ' + a;
  b = ' ' + b;
  if (b[1] == b[2]) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == b[1]) ans++;
    }
    ans = min(n, ans + k);
    cout << (ans * (ans - 1)) / 2 << '\n';
    return 0;
  }
  memset(dp, 128, sizeof(dp));
  for (int i = 0; i <= k; i++) dp[0][i][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 0; l <= i; l++) {
        dp[i][j][l] = dp[i - 1][j][l];
        if (a[i] == b[1])
          dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l - 1]);
        else if (j)
          dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l - 1]);
        if (a[i] == b[2])
          dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l] + l);
        else if (j)
          dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l] + l);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[n][k][i]);
  cout << ans << '\n';
  return 0;
}
