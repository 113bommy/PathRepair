#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const long long mod = 1e9 + 7;
const int inf = 1 << 30;
const int maxn = 1000500;
const double EPS = 1e-7;
char st[maxn];
int cn[26];
const int all = 1 << 18;
int dp[all];
void solve() {
  int n, p;
  scanf("%d%d", &n, &p);
  scanf("%s", st);
  for (int i = 0; i < (int)(n); ++i) st[i] -= 'a', cn[st[i]]++;
  int adj;
  bitset<all> forbid;
  for (int c1 = 0; c1 < (int)(p); ++c1)
    for (int c2 = 0; c2 < (int)(p); ++c2) {
      scanf("%d", &adj);
      if (!adj) {
        bitset<all> bad;
        int la = -1, msk = 0;
        for (int i = 0; i < (int)(n); ++i) {
          if (st[i] == c1) {
            if (la == c2) bad[msk] = 1;
            la = c1;
            msk = 0;
          } else if (st[i] == c2) {
            if (la == c1) bad[msk] = 1;
            la = c2;
            msk = 0;
          } else
            msk |= 1 << st[i];
        }
        for (int ms = 0; ms < (int)(all); ++ms)
          if (bad[ms]) {
            for (int c = 0; c < (int)(p); ++c)
              if (c != c1 && c != c2) bad[ms | (1 << c)] = 1;
          }
        forbid |= bad;
      }
    }
  for (int msk = 0; msk < (int)(all); ++msk)
    if (msk == 0 || dp[msk]) {
      if (forbid[msk]) continue;
      for (int c = 0; c < (int)(p); ++c) {
        if ((msk >> c & 1 ^ 1) && !forbid[msk ^ (1 << c)]) {
          dp[msk ^ (1 << c)] = max(dp[msk ^ (1 << c)], dp[msk] + cn[c]);
        }
      }
    }
  int ret = 0;
  for (int msk = 0; msk < (int)(all); ++msk) ret = max(ret, dp[msk]);
  printf("%d\n", n - ret);
}
int main() {
  int tc = 1;
  for (int tt = 0; tt < (int)(tc); ++tt) {
    solve();
  }
}
