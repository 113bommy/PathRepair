#include <bits/stdc++.h>
using namespace std;
const int N = 100005, K = 20;
int n, Q, dep[N];
int pp, lnk[N], nxt[N * 2], to[N * 2], we[N * 2];
void ae(int k1, int k2, int k3) {
  to[++pp] = k2, we[pp] = k3, nxt[pp] = lnk[k1], lnk[k1] = pp;
}
void dfs(int k1, int k2) {
  for (int i = lnk[k1]; i; i = nxt[i])
    if (to[i] != k2) {
      dep[to[i]] = dep[k1] + we[i];
      dfs(to[i], k1);
    }
}
pair<int, int> getd() {
  dep[1] = 0, dfs(1, 0);
  int rt1 = max_element(dep + 1, dep + 1 + n) - dep;
  dep[rt1] = 0, dfs(rt1, 0);
  int rt2 = max_element(dep + 1, dep + 1 + n) - dep;
  return {rt1, rt2};
}
struct TREE {
  int len[N], son[N], bel[N], dep[N], fa[N][K], rk[N], sum[N], val[N], w[N];
  void dfs1(int k1, int k2) {
    fa[k1][0] = k2;
    for (int i = (1); i <= (K - 1); ++i) fa[k1][i] = fa[fa[k1][i - 1]][i - 1];
    for (int i = lnk[k1]; i; i = nxt[i])
      if (to[i] != k2) {
        dep[to[i]] = dep[k1] + we[i], val[to[i]] = we[i];
        dfs1(to[i], k1);
        if (len[to[i]] + we[i] > len[k1]) {
          len[k1] = len[to[i]] + we[i];
          son[k1] = to[i];
        }
      }
  }
  vector<vector<int> > lian;
  void dfs2(int k1) {
    if (lian.empty() || bel[lian.back().back()] != bel[k1]) {
      lian.push_back({k1});
    } else {
      lian.back().push_back(k1);
    }
    if (son[k1]) {
      bel[son[k1]] = bel[k1];
      dfs2(son[k1]);
    }
    for (int i = lnk[k1]; i; i = nxt[i])
      if (to[i] != fa[k1][0] && to[i] != son[k1]) {
        bel[to[i]] = to[i];
        dfs2(to[i]);
      }
  }
  void pre(int k1) {
    dfs1(k1, 0);
    bel[k1] = k1, dfs2(k1);
    auto getsum = [&](const vector<int>& k1) {
      int res = 0;
      for (auto j : k1) res += val[j];
      return res;
    };
    sort(lian.begin(), lian.end(),
         [&](const vector<int>& k1, const vector<int>& k2) {
           return getsum(k1) > getsum(k2);
         });
    for (int i = 0; i < ((int)(lian).size()); ++i) {
      w[i + 1] = 0;
      for (auto j : lian[i]) {
        rk[j] = i + 1;
        w[i + 1] += val[j];
      }
      sum[i + 1] = sum[i] + w[i + 1];
    }
  }
  int ask(int k1, int k) {
    if (rk[k1] <= k) return sum[min(k, ((int)(lian).size()))];
    int k2 = k1;
    for (int i = K - 1; i >= 0; --i)
      if (rk[fa[k2][i]] > k) k2 = fa[k2][i];
    k2 = fa[k2][0];
    int res = sum[k] - len[bel[k2]] + dep[k1] - dep[k2] + len[k1];
    k2 = k1;
    for (int i = K - 1; i >= 0; --i)
      if (rk[fa[k2][i]] >= k) k2 = fa[k2][i];
    k2 = fa[k2][0];
    res = max(res, sum[k - 1] + dep[k1] - dep[k2] + len[k1]);
    return res;
  }
} A, B;
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = (2); i <= (n); ++i) {
    int k1, k2, k3;
    scanf("%d%d%d", &k1, &k2, &k3);
    ae(k1, k2, k3), ae(k2, k1, k3);
  }
  pair<int, int> rt = getd();
  A.pre(rt.first), B.pre(rt.second);
  int ans = 0;
  for (int _ = (1); _ <= (Q); ++_) {
    int k1, k2;
    scanf("%d%d", &k1, &k2);
    k1 = (k1 + ans - 1) % n + 1;
    k2 = (k2 + ans - 1) % n + 1;
    k2 = k2 * 2 - 1;
    printf("%d\n", ans = max(A.ask(k1, k2), B.ask(k1, k2)));
  }
  return 0;
}
