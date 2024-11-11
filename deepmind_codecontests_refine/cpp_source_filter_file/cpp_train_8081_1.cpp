#include <bits/stdc++.h>
using namespace std;
struct node {
  int ch[26], fi, len, anc, dc;
} t[1000010];
char s1[500010], s2[500010], S[1000010];
int num, las, len, f[1000010], fr[1000010], dp[1000010], pre[1000010];
inline int F(int x) {
  while (S[len] != S[len - t[x].len - 1]) x = t[x].fi;
  return x;
}
inline void build() {
  t[0].fi = t[1].fi = num = las = t[0].anc = 1;
  t[1].len = -1;
}
inline void insert(const register int x) {
  const register int p = F(las);
  if (!t[p].ch[x]) {
    t[++num].len = t[p].len + 2;
    const register int pp = t[F(t[p].fi)].ch[x];
    t[num].fi = pp;
    t[p].ch[x] = num;
    t[num].dc = t[num].len - t[pp].len;
    t[num].anc = t[num].dc == t[pp].dc ? t[pp].anc : pp;
  }
  las = t[p].ch[x];
}
int main() {
  memset(f, 0x3f, sizeof f);
  memset(dp, 0x3f, sizeof dp);
  scanf("%s%s", s1 + 1, s2 + 1);
  const register int n = strlen(s1 + 1);
  for (int i = 1; i <= n; i++) S[i * 2 - 1] = s1[i], S[i * 2] = s2[i];
  build();
  dp[0] = 0;
  for (int i = 1; i <= n * 2; i++) {
    len++;
    insert(S[i] - 'a');
    for (int k = las; k > 1; k = t[k].anc) {
      f[k] = dp[i - t[t[k].anc].len - t[k].dc];
      fr[k] = i - t[t[k].anc].len - t[k].dc;
      if (t[k].anc != t[k].fi && f[t[k].fi] < f[k])
        f[k] = f[t[k].fi], fr[k] = fr[t[k].fi];
      if (!(i & 1) && dp[i] > f[k] + 1) dp[i] = f[k] + 1, pre[i] = fr[k];
    }
    if (!(i & 1) && S[i] == S[i - 1] && dp[i] > dp[i - 2])
      dp[i] = dp[i - 2], pre[i] = i - 2;
  }
  if (dp[n * 2] == dp[n * 2] + 1) return puts("-1"), 0;
  cout << dp[n * 2] << endl;
  for (int i = n * 2; i; i = pre[i])
    if (i - pre[i] > 2) printf("%d %d\n", (pre[i]) / 2 + 1, i / 2);
}
