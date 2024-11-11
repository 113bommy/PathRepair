#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
const int maxx = 8000 + 10;
const long long MOD = 1000000007;
long long dp[maxn][maxx][2];
int a[maxn];
int n, k;
inline long long Mem(int pos, int mask, bool have) {
  long long &ret = dp[pos][mask][have];
  if (ret != -1) return ret;
  if (pos == n + 1) {
    if (have)
      return ret = 1;
    else
      return ret = 0;
  }
  ret = 0;
  if (a[pos] == 2) {
    int now = mask + 2;
    bool check = false;
    if (now >= (1 << k)) check = true;
    if (check || have) {
      ret += Mem(pos + 1, now, 1);
      ret %= MOD;
    } else {
      ret += Mem(pos + 1, now, 0);
      ret %= MOD;
    }
  } else if (a[pos] == 4) {
    int now;
    if (((mask & 2) == 2)) {
      now = 4;
      ret += Mem(pos + 1, now, have);
      ret %= MOD;
    } else {
      now = mask + 4;
      bool check = false;
      if (now >= (1 << k)) check = true;
      if (check || have) {
        ret += Mem(pos + 1, now, 1);
        ret %= MOD;
      } else {
        ret += Mem(pos + 1, now, 0);
        ret %= MOD;
      }
    }
  } else {
    int now = mask + 2;
    bool check = false;
    if (now >= (1 << k)) check = true;
    if (check || have) {
      ret += Mem(pos + 1, now, 1);
      ret %= MOD;
    } else {
      ret += Mem(pos + 1, now, 0);
      ret %= MOD;
    }
    if (((mask & 2) == 2)) {
      now = 4;
      ret += Mem(pos + 1, now, have);
      ret %= MOD;
    } else {
      now = mask + 4;
      check = false;
      if (now >= (1 << k)) check = true;
      if (check || have) {
        ret += Mem(pos + 1, now, 1);
        ret %= MOD;
      } else {
        ret += Mem(pos + 1, now, 0);
        ret %= MOD;
      }
    }
  }
  ret %= MOD;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  cout << Mem(1, 0, 0);
}
