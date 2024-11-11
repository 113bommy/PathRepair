#include <bits/stdc++.h>
using namespace std;
int trs[100010][26], fa[100010], fb[100010], sp[100010], sl = 0;
int insert(char zf[100010], int n) {
  int w = 0;
  for (int i = 0; i < n; i++) {
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
int dl[100010];
void bfs() {
  int he = 0, ta = 1;
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
      else if (u)
        trs[u][i] = trs[sp[u]][i];
    }
  }
}
int wz[100010], st[100010], en[100010], le[100010];
char zf[100010], ch[100010];
struct SJd {
  int l, r, i;
  SJd() {}
  SJd(int L, int R, int I) {
    l = L;
    r = R;
    i = I;
  }
};
vector<SJd> vo[100010];
long long jg[100010];
int xl[100010], xr[100010], tm = 0, fr[100010], ne[200010], v[200010], bs = 0;
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
int he[100010];
struct SXw {
  int u, i, z;
  SXw() {}
  SXw(int U, int I, int Z) {
    u = U;
    i = I;
    z = Z;
  }
};
vector<SXw> ve[100010];
long long ans[100010];
int C[100010];
void add(int i, int x) {
  for (int j = i; j <= tm; j += j & (-j)) C[j] += x;
}
int sum(int i) {
  int jg = 0;
  for (int j = i; j > 0; j -= j & (-j)) jg += C[j];
  return jg;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch);
    int m = strlen(ch);
    wz[i] = insert(ch, m);
    st[i] = en[i - 1] + 1;
    en[i] = st[i] + m - 1;
    le[i] = m;
    for (int j = st[i]; j <= en[i]; j++) zf[j] = ch[j - st[i]];
  }
  bfs();
  for (int i = 0; i <= sl; i++) fr[i] = -1;
  for (int i = 1; i <= sl; i++) addb(sp[i], i);
  dfs(0);
  for (int i = 0; i < q; i++) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    if (le[k] >= 200)
      vo[k].push_back(SJd(l, r, i));
    else {
      int w = 0;
      for (int j = st[k]; j <= en[k]; j++) {
        w = trs[w][zf[j] - 'a'];
        ve[r].push_back(SXw(w, i, 1));
        ve[l - 1].push_back(SXw(w, i, -1));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (le[i] < 200) continue;
    for (int j = 1; j <= tm; j++) he[j] = 0;
    int w = 0;
    long long h = 0;
    for (int j = st[i]; j <= en[i]; j++) {
      w = trs[w][zf[j] - 'a'];
      he[xl[w]] += 1;
    }
    for (int j = 1; j <= tm; j++) he[j] += he[j - 1];
    for (int j = 1; j <= n; j++) {
      int t = wz[j];
      h += (he[xr[t]] - he[xl[t] - 1]);
      jg[j] = h;
    }
    for (int j = 0; j < vo[i].size(); j++) {
      SJd t = vo[i][j];
      ans[t.i] = jg[t.r] - jg[t.l - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    add(xl[wz[i]], 1);
    add(xr[wz[i]] + 1, -1);
    for (int j = 0; j < ve[i].size(); j++) {
      SXw t = ve[i][j];
      ans[t.i] += sum(xl[t.u]) * t.z;
    }
  }
  for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
  return 0;
}
