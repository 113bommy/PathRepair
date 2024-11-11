#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 1e6 + 5;
int par[1];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void join(int x, int y) { par[find(x)] = y; }
long long expo(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (!a) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
const int OFFSET = 100001;
int a[101], b[101];
int dp[101][2 * OFFSET];
int n;
int solve(int i, int bal) {
  int& ans = dp[i][bal];
  if (ans == -1) {
    if (i >= n) {
      if (bal == OFFSET) {
        ans = 0;
      } else {
        ans = -OFFSET;
      }
    } else {
      ans = solve(i + 1, bal);
      ans = max(ans, solve(i + 1, bal + a[i] - b[i]) + a[i]);
    }
  }
  return ans;
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  scanf("%d", &k);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    b[i] *= k;
  }
  memset(dp, -1, sizeof dp);
  if ((j = solve(0, OFFSET)) <= 0) {
    printf("-1\n");
  } else {
    printf("%d\n", j);
  }
  return 0;
}
