#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1e5 + 10;
const int SQ = 320;
long long arr[N_MAX];
vector<int> st[N_MAX];
int id[N_MAX], ptr;
bool have[SQ][N_MAX];
int co[SQ][N_MAX];
long long change[SQ];
long long bans[SQ];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  int sq = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%I64d", arr + i);
  memset(id, 0, sizeof(id));
  memset(have, false, sizeof(have));
  memset(bans, 0, sizeof(bans));
  ptr = 0;
  for (int i = 1; i <= m; i++) {
    int cnt;
    scanf("%d", &cnt);
    if (cnt >= sq) id[i] = ++ptr;
    while (cnt--) {
      int ipt;
      scanf("%d", &ipt);
      bans[id[i]] += arr[ipt];
      st[i].push_back(ipt);
      have[id[i]][ipt] = true;
    }
  }
  memset(co, 0, sizeof(co));
  for (int i = 1; i <= m; i++) {
    for (int u : st[i]) {
      for (int j = 1; j <= ptr; j++) co[j][i] += have[j][u];
    }
  }
  memset(change, 0, sizeof(change));
  while (q--) {
    char cmd[2];
    scanf("%s", cmd);
    if (cmd[0] == '?') {
      int v;
      scanf("%d", &v);
      if (id[v])
        printf("%I64d\n", bans[id[v]]);
      else {
        long long ans = 0;
        for (int i = 1; i <= ptr; i++) ans += change[i] * co[i][v];
        for (int u : st[v]) ans += arr[u];
        printf("%I64d\n", ans);
      }
    } else {
      int v;
      long long val;
      scanf("%d%I64d", &v, &val);
      for (int i = 1; i <= ptr; i++) bans[i] += val * co[i][v];
      if (id[v])
        change[id[v]] += val;
      else {
        for (int u : st[v]) arr[u] += val;
      }
    }
  }
  return 0;
}
