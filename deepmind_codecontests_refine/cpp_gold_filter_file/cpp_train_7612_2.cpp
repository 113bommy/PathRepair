#include <bits/stdc++.h>
using namespace std;
long long dp[200009][5][5], modulo = 1000000007;
int a, b, c;
long long fun(int pos, int last, int mod, int n) {
  if (pos == n) {
    if (mod == 0)
      return 1;
    else
      return 0;
  }
  if (dp[pos][last][mod] != -1) return dp[pos][last][mod];
  dp[pos][last][mod] = 0;
  if (a) {
    long long k = a;
    dp[pos][last][mod] += (k * fun(pos + 1, 0, mod, n));
    dp[pos][last][mod] %= modulo;
  }
  if (b) {
    long long k = b;
    dp[pos][last][mod] += (k * fun(pos + 1, 1, (mod + 1) % 3, n));
    dp[pos][last][mod] %= modulo;
  }
  if (c) {
    long long k = c;
    dp[pos][last][mod] += (k * fun(pos + 1, 2, (mod + 2) % 3, n));
    dp[pos][last][mod] %= modulo;
  }
  return dp[pos][last][mod];
}
int main() {
  memset(dp, -1, sizeof(dp));
  int l, r, n, i;
  scanf("%d %d %d", &n, &l, &r);
  if (l > r) swap(l, r);
  if (l % 3 == 1) b = 1, l++;
  if (l % 3 == 2 && l <= r) c = 1, l++;
  if (l <= r) {
    a = r / 3 - l / 3;
    b += a;
    c += a;
    if (l % 3 == 0) a++;
    if (r % 3 == 2 && r > l) c++, r--;
    if (r % 3 == 1 && r > l) b++, r--;
  }
  printf("%lld\n", fun(0, 0, 0, n));
  return 0;
}
