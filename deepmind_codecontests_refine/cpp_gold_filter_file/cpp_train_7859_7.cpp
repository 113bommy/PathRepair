#include <bits/stdc++.h>
using namespace std;
const int pw = 1e7 + 19, md = 1e9 + 7;
int P[1010];
int n, k, q;
int v[15010], w[15010];
int s[15010], t[15010];
bool ask[30010];
int dp[20][1010];
void cdq(int l, int r, int d, vector<int> p) {
  for (int i = 1; i <= k; i++) dp[d][i] = dp[d - 1][i];
  for (int i = 0; i < (int)p.size(); i++)
    if (s[p[i]] <= l && t[p[i]] >= r)
      for (int j = k; j >= w[p[i]]; j--)
        dp[d][j] = max(dp[d][j], dp[d][j - w[p[i]]] + v[p[i]]);
  if (l == r) {
    if (ask[l]) {
      int ans = 0;
      for (int i = 1; i <= k; i++)
        ans = (ans + 1LL * dp[d][i] * P[i - 1] % md) % md;
      printf("%d\n", ans);
    }
    return;
  }
  int mid = (l + r) >> 1;
  vector<int> L, R;
  for (int i = 0; i < (int)p.size(); i++) {
    if (s[p[i]] <= l && t[p[i]] >= r) continue;
    if (s[p[i]] <= mid) L.push_back(p[i]);
    if (t[p[i]] > mid) R.push_back(p[i]);
  }
  cdq(l, mid, d + 1, L);
  cdq(mid + 1, r, d + 1, R);
}
int main() {
  scanf("%d%d", &n, &k);
  P[0] = 1;
  for (int i = 1; i <= k; i++) P[i] = 1LL * P[i - 1] * pw % md;
  for (int i = 1; i <= n; i++) scanf("%d%d", v + i, w + i);
  scanf("%d", &q);
  for (int i = 1; i <= n; i++) s[i] = 1, t[i] = q;
  for (int i = 1; i <= q; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      n++;
      s[n] = i;
      t[n] = q;
      scanf("%d%d", v + n, w + n);
    } else if (op == 2) {
      int x;
      scanf("%d", &x);
      t[x] = i - 1;
    } else
      ask[i] = true;
  }
  vector<int> p;
  for (int i = 1; i <= n; i++) p.push_back(i);
  cdq(1, q, 1, p);
  return 0;
}
