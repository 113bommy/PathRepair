#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int jt = 1000000007;
void inline add(int &a, int b) {
  a += b;
  if (a >= jt) a -= jt;
}
int n, k;
int a[55], b[55], y[55];
vector<pair<int, int> > nei[200005];
vector<int> lsa, lsb;
int jc[100005];
long long suf[55];
map<long long, int> dp[55][55];
int main() {
  scanf("%d%d", &n, &k);
  jc[0] = 1;
  for (int i = 1; i <= (n); ++i) jc[i] = 1ll * jc[i - 1] * i % jt;
  for (int i = 1; i <= (k); ++i) {
    scanf("%d%d%d", a + i, b + i, y + i);
    --y[i];
    lsa.push_back(a[i]);
    lsb.push_back(b[i]);
  }
  sort((lsa).begin(), (lsa).end());
  sort((lsb).begin(), (lsb).end());
  int as = ((int)(lsa).size());
  for (int i = 1; i <= (k); ++i) {
    a[i] = lower_bound((lsa).begin(), (lsa).end(), a[i]) - lsa.begin();
    b[i] = lower_bound((lsb).begin(), (lsb).end(), b[i]) - lsb.begin();
    nei[a[i]].push_back(make_pair(b[i], y[i]));
  }
  for (int i = (as - 1); (-1) > 0 ? i <= (0) : i >= (0); i += (-1)) {
    suf[i] = suf[i + 1];
    for (int j = 0; j < (((int)(nei[i]).size())); ++j)
      suf[i] |= 1 << nei[i][j].first;
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < (as); ++i)
    for (int j = 0; j < (i + 1); ++j)
      for (__typeof((dp[i][j]).begin()) it = (dp[i][j]).begin();
           it != (dp[i][j]).end(); ++it) {
        add(dp[i + 1][j][it->first & suf[i + 1]], it->second);
        for (int k = 0; k < (((int)(nei[i]).size())); ++k) {
          int to = nei[i][k].first;
          if (!((it->first >> to) & 1)) {
            add(dp[i + 1][j + 1][(it->first | (1 << to)) & suf[i + 1]],
                1ll * it->second * nei[i][k].second % jt);
          }
        }
      }
  int ans = 0;
  for (int i = 0; i < (as + 1); ++i)
    for (__typeof((dp[as][i]).begin()) it = (dp[as][i]).begin();
         it != (dp[as][i]).end(); ++it) {
      ans = (ans + 1ll * it->second * jc[n - i]) % jt;
    }
  printf("%d\n", ans);
  return 0;
}
