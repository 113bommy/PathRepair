#include <bits/stdc++.h>
using namespace std;
int trs[200010][26], sl = 0, fa[200010], fb[200010];
int insert(char zf[200010]) {
  int w = 0;
  for (int i = 0; zf[i] != 0; i++) {
    int s = zf[i] - 'a';
    if (trs[w][s] == 0) {
      trs[w][s] = ++sl;
      fa[sl] = w;
      fb[sl] = s;
    }
    w = trs[w][s];
  }
  return w;
}
int dl[200010], sp[200010];
void bfs() {
  int he = 0, ta = 1;
  dl[he] = 0;
  while (he < ta) {
    int u = dl[he++];
    if (u == 0)
      sp[u] = -1;
    else if (fa[u] == 0)
      sp[u] = 0;
    else
      sp[u] = trs[sp[fa[u]]][fb[u]];
    for (int i = 0; i < 26; i++) {
      if (trs[u][i])
        dl[ta++] = trs[u][i];
      else if (u != 0)
        trs[u][i] = trs[sp[u]][i];
    }
  }
}
char zf[200010];
int wz[200010];
int xl[200010], xr[200010], tm = 0;
int fr[200010], ne[200010], v[200010], bs = 0;
void addb(int a, int b) {
  v[bs] = b;
  ne[bs] = fr[a];
  fr[a] = bs++;
}
void dfs(int u) {
  xl[u] = ++tm;
  for (int i = fr[u]; i != -1; i = ne[i]) dfs(v[i]);
  xr[u] = tm;
}
int C[200010];
void add(int i, int x) {
  for (int j = i; j <= tm; j += j & (-j)) C[j] += x;
}
int sum(int i) {
  int jg = 0;
  for (int j = i; j > 0; j -= j & (-j)) jg += C[j];
  return jg;
}
struct SJd {
  int u, i, z;
  SJd() {}
  SJd(int U, int I, int Z) {
    u = U;
    i = I;
    z = Z;
  }
};
vector<SJd> ve[200010];
int ans[500010];
string st[200010];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", zf);
    wz[i] = insert(zf);
    st[i] = zf;
  }
  bfs();
  for (int i = 0; i < q; i++) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    ve[r].push_back(SJd(wz[k], i, 1));
    if (l > 1) ve[l - 1].push_back(SJd(wz[k], i, -1));
  }
  for (int i = 0; i <= sl; i++) fr[i] = -1;
  for (int i = 1; i <= sl; i++) addb(sp[i], i);
  dfs(0);
  for (int i = 1; i <= n; i++) {
    int w = 0;
    for (int j = 0; j < st[i].length(); j++) {
      w = trs[w][st[i][j] - 'a'];
      add(xl[w], 1);
    }
    for (int j = 0; j < ve[i].size(); j++) {
      int u = ve[i][j].u;
      ans[ve[i][j].i] += ve[i][j].z * (sum(xr[u]) - sum(xl[u] - 1));
    }
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
