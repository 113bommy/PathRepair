#include <bits/stdc++.h>
using namespace std;
const int maxn = 66, mod = 1e9 + 7;
int a[maxn];
vector<int> base, other;
bool mark[maxn];
vector<int> bm, om;
vector<pair<int, int> > sol;
void dfs(int u, bool state) {
  mark[u] = 1;
  if (state == 0) {
    bm.push_back(u);
    for (int x : other)
      if (mark[x] == 0 && x % u == 0) dfs(x, 1);
  } else {
    om.push_back(u);
    for (int x : base)
      if (mark[x] == 0 && u % x == 0) dfs(x, 0);
  }
}
int dp[1 << 20], MSK[maxn], CNT[1 << 20];
int fac[maxn], C[maxn][maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 0; i < maxn; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    bool ok = 1;
    for (int j = 0; j < n; j++) {
      if (j != i && a[i] % a[j] == 0) ok = 0;
    }
    if (ok && a[i] <= 20) base.push_back(a[i]);
    if (!ok) other.push_back(a[i]);
  }
  int ans = 1, ansc = 0;
  for (int _ : base) {
    if (mark[_]) continue;
    bm.clear(), om.clear();
    dfs(_, 0);
    if (int((om).size()) == 0) continue;
    for (int msk = 0; msk < (1 << int((bm).size())); msk++) {
      CNT[msk] = 0;
    }
    for (int i = 0; i < int((om).size()); i++) {
      MSK[i] = 0;
      for (int j = 0; j < int((bm).size()); j++)
        if (om[i] % bm[j] == 0) MSK[i] |= 1 << j;
      CNT[MSK[i]]++;
    }
    for (int i = 0; i < int((bm).size()); i++) {
      for (int msk = (1 << int((bm).size())) - 1; msk >= 0; msk--) {
        if ((((msk) >> (i)) & 1)) CNT[msk] += CNT[msk ^ (1 << i)];
      }
    }
    for (int msk = 0; msk < (1 << int((bm).size())); msk++) {
      dp[msk] = CNT[msk] == int((om).size());
    }
    for (int msk = (1 << int((bm).size())) - 1; msk >= 0; msk--) {
      for (int i = 0; i < int((om).size()); i++) {
        if (msk != 0) {
          if ((MSK[i] & msk) == MSK[i]) continue;
          if ((MSK[i] & msk) == 0) continue;
        }
        int msk2 = MSK[i] | msk;
        int cnt2 = CNT[msk2] - CNT[msk] - 1,
            cnt3 = int((om).size()) - CNT[msk2];
        int num = 1ll * dp[msk2] * C[cnt3 + cnt2][cnt2] % mod * fac[cnt2] % mod;
        dp[msk] = (dp[msk] + num) % mod;
      }
    }
    ansc += int((om).size()) - 1;
    ans = 1ll * ans * dp[0] % mod * C[ansc][int((om).size()) - 1] % mod;
  }
  if (ans < 0) ans += mod;
  return cout << ans << endl, 0;
}
