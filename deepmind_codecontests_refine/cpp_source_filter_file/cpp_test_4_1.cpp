#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 9;
const int P = 1000000000 + 7;
const int inv2 = (P + 1) / 2;
inline int add(int a, int b) { return a + b < P ? a + b : a + b - P; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + P : a - b; }
inline int mul(int a, int b) { return (long long)a * b % P; }
int n, K, a[N], ans;
vector<pair<int, int>> G[N];
int rt, tot, msz, top, sz[N];
bool vis[N];
void dfs1(int u, int p) {
  int _max = 0;
  sz[u] = 1;
  for (auto [v, w] : G[u])
    if (!vis[v] && v != p) {
      dfs1(v, u);
      sz[u] += sz[v];
      _max = max(_max, sz[v]);
    }
  _max = max(_max, tot - sz[u]);
  if (_max < msz) {
    msz = _max;
    rt = u;
  }
}
vector<int> cnt[N], C[2], sum[N], S[2];
void dfs3(int u, int p, int c, int k, int ans) {
  if (k > K) return;
  cnt[top][k] = add(cnt[top][k], 1);
  sum[top][k] = add(sum[top][k], ans);
  for (auto [v, w] : G[u])
    if (!vis[v] && v != p) {
      dfs3(v, u, w, k + (c != w), add(ans, a[v]));
    }
}
void dfs2(int u, int _tot) {
  tot = _tot;
  msz = tot + 1;
  dfs1(u, 0);
  vis[rt] = true;
  int _sz = sz[rt];
  C[0].resize(min(K + 1, _tot));
  fill(C[0].begin(), C[0].end(), 0);
  C[1].resize(min(K + 1, _tot));
  fill(C[1].begin(), C[1].end(), 0);
  S[0].resize(min(K + 1, _tot));
  fill(S[0].begin(), S[0].end(), 0);
  S[1].resize(min(K + 1, _tot));
  fill(S[1].begin(), S[1].end(), 0);
  for (auto [v, w] : G[rt])
    if (!vis[v]) {
      top = v;
      cnt[v].resize(min(K + 1, sz[v] < _sz ? sz[v] : _tot - _sz));
      fill(cnt[v].begin(), cnt[v].end(), 0);
      sum[v].resize(min(K + 1, sz[v] < _sz ? sz[v] : _tot - _sz));
      fill(sum[v].begin(), sum[v].end(), 0);
      dfs3(v, rt, w, 0, a[v]);
      for (int i = 0, ed = cnt[v].size(); i < ed; ++i) {
        C[w][i] = add(C[w][i], cnt[v][i]);
        S[w][i] = add(S[w][i], sum[v][i]);
      }
    }
  ans = add(ans, a[rt]);
  for (int i = 0, ed = C[0].size(); i < ed; ++i) {
    ans = add(ans, add(mul(a[rt], C[0][i]), S[0][i]));
    ans = add(ans, add(mul(a[rt], C[1][i]), S[1][i]));
  }
  for (int i = 1, ed = C[0].size(); i < ed; ++i) {
    C[0][i] = add(C[0][i], C[0][i - 1]);
    C[1][i] = add(C[1][i], C[1][i - 1]);
    S[0][i] = add(S[0][i], S[0][i - 1]);
    S[1][i] = add(S[1][i], S[1][i - 1]);
  }
  int tmp = 0;
  for (auto [v, w] : G[rt])
    if (!vis[v]) {
      for (int i = 1, ed = cnt[v].size(); i < ed; ++i) {
        cnt[v][i] = add(cnt[v][i], cnt[v][i - 1]);
        sum[v][i] = add(sum[v][i], sum[v][i - 1]);
      }
      for (int i = 0, ed = cnt[v].size(); i < ed; ++i) {
        C[w][i] = sub(C[w][i], cnt[v][i]);
        S[w][i] = sub(S[w][i], sum[v][i]);
      }
      int cntv_back = cnt[v].back();
      int sumv_back = sum[v].back();
      for (int i = cnt[v].size() - 1; i >= 1; --i) {
        cnt[v][i] = sub(cnt[v][i], cnt[v][i - 1]);
        sum[v][i] = sub(sum[v][i], sum[v][i - 1]);
      }
      for (int i = 0, ed = cnt[v].size(); i < ed; ++i) {
        int j = min(K - i, (int)C[0].size());
        tmp = add(tmp, mul(cnt[v][i], sub(S[w][j], j < ed ? 0 : sumv_back)));
        tmp = add(tmp, mul(sum[v][i], sub(C[w][j], j < ed ? 0 : cntv_back)));
        tmp = add(tmp, mul(a[rt], mul(cnt[v][i],
                                      sub(C[w][j], j < ed ? 0 : cntv_back))));
        if (i < K) {
          int j = min(K - i - 1, (int)C[0].size());
          tmp = add(tmp, mul(cnt[v][i], S[w ^ 1][j]));
          tmp = add(tmp, mul(sum[v][i], C[w ^ 1][j]));
          tmp = add(tmp, mul(a[rt], mul(cnt[v][i], C[w ^ 1][j])));
        }
      }
      for (int i = 1, ed = cnt[v].size(); i < ed; ++i) {
        cnt[v][i] = add(cnt[v][i], cnt[v][i - 1]);
        sum[v][i] = add(sum[v][i], sum[v][i - 1]);
      }
      for (int i = 0, ed = cnt[v].size(); i < ed; ++i) {
        C[w][i] = add(C[w][i], cnt[v][i]);
        S[w][i] = add(S[w][i], sum[v][i]);
      }
    }
  ans = add(ans, mul(tmp, inv2));
  for (auto [v, w] : G[rt])
    if (!vis[v]) {
      dfs2(v, sz[v] < _sz ? sz[v] : _tot - _sz);
    }
}
int main() {
  scanf("%d %d", &n, &K);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  dfs2(1, n);
  printf("%d\n", ans);
  return 0;
}
