#include <bits/stdc++.h>
using namespace std;
const int maxn = 23;
const int maxS = 1 << 21;
const int inf = 1 << 30;
int n, m, cnt[maxn][maxn], d[maxS][maxn], dp[maxS], cntBit[maxS], minBit[maxS];
char s[100010];
void upd(int &a, int b) {
  if (a > b) a = b;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  for (int i = 1; i < n; ++i) {
    ++cnt[s[i] - 'a'][s[i - 1] - 'a'];
    ++cnt[s[i - 1] - 'a'][s[i] - 'a'];
  }
  for (int i = 1; i < (1 << m); ++i) dp[i] = inf;
  for (int msk = 1; msk < (1 << m); ++msk) {
    cntBit[msk] = 1 + cntBit[msk & (msk - 1)];
    for (int i = 0; i < m; ++i)
      if (msk >> i & 1) {
        minBit[msk] = i;
        break;
      }
  }
  for (int msk = 0; msk < (1 << m); ++msk) {
    for (int i = 0; i < m; ++i)
      d[msk][i] = d[msk ^ (1 << minBit[msk])][i] + cnt[i][minBit[msk]];
  }
  for (int msk = 0; msk < (1 << m); ++msk) {
    for (int i = 0; i < m; ++i) {
      if (msk >> i & 1) continue;
      int pos = cntBit[msk];
      int nmsk = msk | (1 << i);
      upd(dp[nmsk], dp[msk] + pos * (d[msk][i] - d[((1 << m) - 1) ^ nmsk][i]));
    }
  }
  cout << dp[(1 << m) - 1] << endl;
  return 0;
}
