#include <bits/stdc++.h>
using namespace std;
namespace FGF {
int n[3], m;
const int N = 1e6 + 5, mo = 1e9 + 7;
int trans[N][26], siz[3][N], len[N], lk[N], tot = 1, lst = 1;
long long ans[N];
void inser(int x, int i) {
  if (trans[lst][x]) {
    int q = trans[lst][x], tmp = lst;
    if (len[q] == len[tmp] + 1)
      lst = q;
    else {
      int cl = ++tot;
      len[cl] = len[tmp] + 1, lk[cl] = lk[q];
      memcpy(trans[cl], trans[q], sizeof(trans[cl]));
      for (; tmp && trans[tmp][x] == q; tmp = lk[tmp]) trans[tmp][x] = cl;
      lk[q] = cl, lst = cl;
    }
    siz[i][lst]++;
    return;
  }
  int cur = ++tot, tmp = lst;
  lst = cur;
  siz[i][cur]++, len[cur] = len[tmp] + 1;
  for (; tmp && !trans[tmp][x]; tmp = lk[tmp]) trans[tmp][x] = cur;
  if (!tmp)
    lk[cur] = 1;
  else {
    int q = trans[tmp][x];
    if (len[q] == len[tmp] + 1)
      lk[cur] = q;
    else {
      int cl = ++tot;
      len[cl] = len[tmp] + 1, lk[cl] = lk[q];
      memcpy(trans[cl], trans[q], sizeof(trans[cl]));
      for (; tmp && trans[tmp][x] == q; tmp = lk[tmp]) trans[tmp][x] = cl;
      lk[q] = lk[cur] = cl;
    }
  }
}
char s[N];
vector<int> g[N];
void dfs(int u) {
  for (auto v : g[u]) {
    dfs(v);
    for (int i = 0; i < 3; i++) siz[i][u] += siz[i][v];
  }
  ans[len[u]] += 1ll * siz[0][u] * siz[1][u] % mo * siz[2][u] % mo,
      ans[len[lk[u]]] -= 1ll * siz[0][u] * siz[1][u] % mo * siz[2][u] % mo;
}
void work() {
  for (int i = 0; i < 3; i++) {
    scanf("%s", s);
    lst = 1;
    n[i] = strlen(s);
    for (int j = 0; j < n[i]; j++) inser(s[j] - 'a', i);
  }
  for (int i = 2; i <= tot; i++) g[lk[i]].push_back(i);
  dfs(1);
  for (int i = tot; i; i--) ans[i] = ((ans[i] + ans[i + 1]) % mo + mo) % mo;
  for (int i = 1; i <= min(n[0], min(n[1], n[2])); i++)
    printf("%lld ", ans[i] % mo);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
