#include <bits/stdc++.h>
using namespace std;
long long int m, k;
long long int dp[70][2][70];
long long int getans(long long int num, int pos, int cap, int k) {
  if (k < 0) return 0;
  if (pos == -1) return k == 0;
  long long int &ret = dp[pos][cap][k];
  if (ret == -1) {
    ret = 0;
    int cbit = 0;
    if ((num & (1LL << pos))) {
      cbit = 1;
    }
    if (cbit == 1 || cap) ret += getans(num, pos - 1, cap, k - 1);
    ret += getans(num, pos - 1, (cap || cbit), k);
  }
  return ret;
}
long long int getcnt(long long int num, int k) {
  memset(dp, -1, sizeof(dp));
  long long int tnum = num;
  int pos = 0;
  while (tnum) {
    tnum >>= 1;
    if (tnum != 0) pos++;
  }
  return getans(num, pos, 0, k);
}
void check(long long int n) {
  long long int ans = 0;
  for (long long int i = n + 1; i <= n + n; i++) {
    if (__builtin_popcount(i) == k) ans++;
  }
  assert(ans == m);
}
int main() {
  int i;
  cin >> m >> k;
  long long int lb = 1, ub = 1e18, mid, ans;
  while (lb <= ub) {
    mid = (lb + ub) / 2;
    long long int cnt = getcnt(2 * mid, k) - getcnt(mid, k);
    if (cnt == m) {
      cout << mid << endl;
      return 0;
    } else if (cnt > m) {
      ub = mid - 1;
    } else {
      lb = mid + 1;
    }
  }
  assert(false);
  return 0;
}
