#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
const int SQRN = 210;
const int BSZ = 256;
vector<int> g[MAXN];
int v[MAXN], lvl[MAXN], pai[MAXN];
int jump[MAXN], best[MAXN][SQRN];
int trie[BSZ * 20 + 5][2];
int n, q, cnt_trie = 1;
void predfs(int cur, int p) {
  for (auto viz : g[cur]) {
    if (viz == p) continue;
    lvl[viz] = lvl[cur] + 1;
    pai[viz] = cur;
    predfs(viz, cur);
  }
}
void build(int cur, int k, int root) {
  if (k >= BSZ) return;
  jump[root] = cur;
  int val = v[cur] ^ k;
  int tcur = 1;
  for (int i = 16; i >= 0; i--) {
    bool viz = val & (1 << i);
    if (!trie[tcur][viz]) trie[tcur][viz] = ++cnt_trie;
    tcur = trie[tcur][viz];
  }
  if (pai[cur] == cur) return;
  build(pai[cur], k + 1, root);
}
int find_best(int mask) {
  int cur = 1;
  int resp = 0;
  for (int i = 16; i >= 0; i--) {
    bool want = 1 ^ ((bool)(mask & (1 << i)));
    if (trie[cur][want])
      cur = trie[cur][want], resp += (1 << i);
    else
      cur = trie[cur][!want];
  }
  return resp;
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  pai[1] = 1;
  predfs(1, 1);
  for (int i = 1; i <= n; i++) {
    build(i, 0, i);
    for (int k = 0; k * BSZ <= n; k++) best[i][k] = find_best(k * BSZ);
    memset(trie, 0, sizeof(trie));
    cnt_trie = 1;
  }
  while (q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int w = 0;
    int respf = 0;
    while (lvl[jump[b]] > lvl[a]) {
      respf = max(respf, best[b][w]);
      b = pai[jump[b]];
      w++;
    }
    int dist = w * BSZ;
    while (b != a) {
      respf = max(respf, v[b] ^ dist);
      b = pai[b];
      dist++;
    }
    respf = max(respf, v[a] ^ dist);
    printf("%d\n", respf);
  }
}
