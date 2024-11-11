#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
long long nmpow(long long a, long long n) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b);
    b = (b * b);
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
long long dp[12][1111], x;
int n, prim[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int lim[11];
long long getans(int i, int x) {
  if (i == 11) {
    if (x == 1) {
      return 1;
    } else {
      return 0;
    }
  }
  if (x == 1) {
    return 1;
  }
  if (dp[i][x] != -1) return dp[i][x];
  long long &ret = dp[i][x];
  ret = 1e19;
  for (int p = 0; p <= lim[i]; p++) {
    if (x % (p + 1) == 0) {
      long long nval = nmpow(prim[i], p) * getans(i + 1, x / (p + 1));
      if (nval <= 0) {
        continue;
      }
      ret = min(ret, nval);
    }
  }
  if (ret == x) ret = 0;
  return ret;
}
void solve() {
  scanf("%d", &n);
  memset(dp, -1, sizeof(dp));
  x = 1e18;
  for (int i = 1; i <= 10; i++) {
    long long p = prim[i], val = 1;
    int cnt = 0;
    while (val <= x) {
      cnt++;
      val *= p;
    }
    lim[i] = --cnt;
  }
  cout << getans(1, n);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
