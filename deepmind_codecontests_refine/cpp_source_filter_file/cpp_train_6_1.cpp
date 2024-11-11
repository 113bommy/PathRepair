#include <bits/stdc++.h>
using namespace std;
int M = 0, fst[666666], vb[666666], nxt[666666], vc[666666];
void ad_de(int a, int b, int c) {
  ++M;
  nxt[M] = fst[a];
  fst[a] = M;
  vb[M] = b;
  vc[M] = c;
}
void adde(int a, int b, int c) {
  ad_de(a, b, c);
  ad_de(b, a, c);
}
map<int, int> vis;
int n, s, a[666666], b[666666], id, vv[666666], ed;
vector<int> cur, vs[666666];
int vn;
void dfs(int x) {
  for (int& e = fst[x]; e; e = nxt[e])
    if (!vv[vc[e]]) {
      int c = vc[e];
      vv[vc[e]] = 1;
      dfs(vb[e]);
      cur.push_back(c);
    }
}
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), vis[a[i]] = 1;
  for (auto& t : vis) t.second = ++id;
  for (int i = 1; i <= n; ++i) b[i] = a[i] = vis[a[i]];
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; ++i)
    if (a[i] != b[i]) ++ed, ad_de(a[i], b[i], i);
  if (ed > s) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= id; ++i)
    if (fst[i]) {
      dfs(i);
      vs[++vn] = cur;
      cur.clear();
    }
  int tj = min(vn, s - ed);
  if (tj <= 2) tj = 0;
  vector<int> ta, tb;
  for (int i = 1; i <= tj; ++i) {
    ta.insert(ta.end(), vs[vn].begin(), vs[vn].end());
    tb.push_back(vs[vn--].back());
  }
  if (tj) {
    reverse(tb.begin(), tb.end());
    vs[++vn] = ta;
    vs[++vn] = tb;
  }
  printf("%d\n", vn);
  for (int i = 1; i <= vn; ++i) {
    printf("%d\n", int(vs[i].size()));
    for (auto g : vs[i]) printf("%d ", g);
    puts("");
  }
}
