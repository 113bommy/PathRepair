#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int v[2020];
int tp[25];
int vis[2020][2020];
int pre[15020][4];
int biggest[15020][4];
int Kay, n;
long long pow2[2020];
long long mem[2020][2020];
vector<int> vv;
long long get(int pos, int mask) {
  if (pos == n) return 0;
  if (vis[pos][mask]) return mem[pos][mask];
  long long ret = 0;
  int i;
  if (v[pos] == 0) {
    for (i = 0; i < 2; i++) {
      int then = biggest[mask][vv[i]];
      if (then >= Kay)
        ret = (ret + pow2[pos + 1]) % mod;
      else
        ret = (ret + get(pos + 1, pre[mask][vv[i]])) % mod;
    }
  } else {
    int then = biggest[mask][v[pos]];
    if (then >= Kay)
      ret = pow2[pos + 1];
    else
      ret = (ret + get(pos + 1, pre[mask][v[pos]])) % mod;
  }
  vis[pos][mask] = 1;
  mem[pos][mask] = ret;
  return ret;
}
int main() {
  int i, j, val, k;
  vv.push_back(1);
  vv.push_back(2);
  for (i = 0; i < 4; i++) tp[1 << i] = i;
  scanf("%d %d", &n, &Kay);
  for (i = 0; i < n; i++) {
    scanf("%d", &val);
    v[i] = (tp[val]);
  }
  pow2[n] = 1;
  for (i = n - 1; i >= 0; i--) {
    if (v[i] == 0)
      pow2[i] = (((long long)2) * pow2[i + 1]) % mod;
    else
      pow2[i] = pow2[i + 1];
  }
  for (i = 0; i < (1 << 13); i++)
    for (j = 1; j <= 2; j++) {
      int now = i;
      k = j;
      if (((1 << j) - 1) & i) {
        pre[i][j] = 1 << j;
        biggest[i][j] = k;
        continue;
      }
      while ((1 << k) & i) {
        now ^= (1 << k);
        k++;
      }
      now ^= 1 << k;
      pre[i][j] = now;
      biggest[i][j] = k;
    }
  long long ret = get(0, 0);
  printf("%I64d\n", ret);
  return 0;
}
