#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 150005;
char c[maxn], C;
int cnt[maxn][30], f[maxn][30];
vector<int> G[maxn], G2[maxn];
int b, fa[maxn], len[maxn], sum[maxn], v, id[maxn];
void dfs(int rt) {
  for (auto i : G[rt]) dfs(i);
  if (G[rt].size() != 0) len[rt] = len[G[rt][0]] + 1;
  if (G[rt].size() == 1)
    id[rt] = id[G[rt][0]];
  else {
    id[rt] = rt;
    for (auto i : G[rt]) {
      fa[id[i]] = rt;
      G2[rt].push_back(id[i]);
    }
  }
}
int Sum;
void update(int c, int rt, int k) {
  cnt[rt][c] += k;
  for (rt = fa[rt]; rt != 0; rt = fa[rt]) {
    Sum -= sum[rt] > len[id[rt]];
    sum[rt] -= f[rt][c];
    int cc = 0;
    for (auto i : G2[rt]) cc = max(cc, cnt[i][c] + f[i][c]);
    f[rt][c] = cc;
    sum[rt] += f[rt][c];
    Sum += sum[rt] > len[id[rt]];
  }
}
long long ans;
int p;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++) {
    scanf("%d %c", &b, &c[i]);
    G[b].push_back(i);
  }
  dfs(1);
  for (int i = 2; i <= n; i++)
    if (c[i] != '?') update(c[i] - 'a', id[i], 1);
  for (int i = 1; i <= m; i++) {
    scanf("%d %c", &v, &C);
    if (c[v] != '?') update(c[v] - 'a', id[v], -1);
    c[v] = C;
    if (c[v] != '?') update(c[v] - 'a', id[v], 1);
    if (Sum)
      cout << "Fou" << '\n';
    else {
      cout << "Shi" << ' ';
      ans = 0;
      p = len[1];
      for (int j = 0; j < 26; j++) {
        ans = ans + (cnt[id[1]][j] + f[id[1]][j]) * (j + 1);
        p -= cnt[id[1]][j] + f[id[1]][j];
      }
      cout << ans + 1ll * p * 27 * 13 << '\n';
    }
  }
}
