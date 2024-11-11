#include <bits/stdc++.h>
const int maxn = 1e5 + 20;
const int inf = 0x3f3f3f3f;
int N, Y, K, X;
int V[maxn];
int powk[maxn], revk[maxn];
std::vector<int> G[maxn];
int size[maxn];
bool flag[maxn];
int in[maxn], out[maxn];
struct Node {
  int ind, from, pre, sur, vpre;
};
std::vector<int> v[maxn];
std::map<int, int> cnt, cntt;
std::vector<Node> w;
void getsize(int a, int fa) {
  size[a] = 1;
  for (int i = 0; i < G[a].size(); i++)
    if (G[a][i] != fa && !flag[G[a][i]]) {
      getsize(G[a][i], a);
      size[a] += size[G[a][i]];
    }
}
std::pair<int, int> getroot(int a, int fa, int tot) {
  std::pair<int, int> ret = std::make_pair(inf, 0);
  int maxsub = 0;
  for (int i = 0; i < G[a].size(); i++)
    if (G[a][i] != fa && !flag[G[a][i]]) {
      ret = std::min(ret, getroot(G[a][i], a, tot));
      maxsub = std::max(maxsub, size[G[a][i]]);
    }
  maxsub = std::max(maxsub, tot - size[a]);
  ret = std::min(ret, std::make_pair(maxsub, a));
  return ret;
}
int center(int a) { return getsize(a, 0), getroot(a, 0, size[a]).second; }
void dfs(int a, int from, int fa, int vs, int vt, int l) {
  int vp = 0;
  vs = (V[a] + 1LL * vs * K) % Y;
  vt = (vt + 1LL * V[a] * powk[l]) % Y;
  vp = 1LL * (X - vs + Y) % Y * revk[l] % Y;
  w.push_back((Node){a, from, vs, vt, vp});
  for (int i = 0; i < G[a].size(); i++)
    if (G[a][i] != fa && !flag[G[a][i]]) dfs(G[a][i], from, a, vs, vt, l + 1);
}
void solve(int a) {
  flag[a] = true, w.clear();
  if (V[a] == X) in[a]++, out[a]++;
  for (int i = 0; i < G[a].size(); i++)
    if (!flag[G[a][i]]) dfs(G[a][i], i, 0, V[a], V[a], 1);
  cnt.clear(), cntt.clear();
  for (int i = 0; i < w.size(); i++) {
    (w[i].vpre += V[a]) %= Y;
    if (w[i].pre == X) out[w[i].ind]++, in[a]++;
    if (w[i].sur == X) in[w[i].ind]++, out[a]++;
    if (!cnt.count(w[i].vpre))
      cnt[w[i].vpre] = 1;
    else
      cnt[w[i].vpre]++;
    if (!cntt.count(w[i].sur))
      cntt[w[i].sur] = 1;
    else
      cntt[w[i].sur]++;
  }
  for (int i = 0; i < w.size(); i++) {
    if (cntt.count(w[i].vpre)) out[w[i].ind] += cntt[w[i].vpre];
    if (cnt.count(w[i].sur)) in[w[i].ind] += cnt[w[i].sur];
  }
  for (int i = 0, j = 0; i < w.size(); i = j) {
    while (j < w.size() && w[i].from == w[j].from) j++;
    cnt.clear(), cntt.clear();
    for (int k = i; k < j; k++) {
      if (!cnt.count(w[k].vpre))
        cnt[w[k].vpre] = 1;
      else
        cnt[w[k].vpre]++;
      if (!cntt.count(w[k].sur))
        cntt[w[k].sur] = 1;
      else
        cntt[w[k].sur]++;
    }
    for (int k = i; k < j; k++) {
      if (cntt.count(w[k].vpre)) out[w[k].ind] -= cntt[w[k].vpre];
      if (cnt.count(w[k].sur)) in[w[k].ind] -= cnt[w[k].sur];
    }
  }
  if (a == 4)
    for (int i = 0; i < w.size(); i++)
      std::cerr << w[i].ind << ' ' << w[i].sur << ' ' << w[i].vpre << std::endl;
  for (int i = 0; i < G[a].size(); i++)
    if (!flag[G[a][i]]) solve(center(G[a][i]));
}
long long powermod(long long x, long long y, long long mod) {
  long long r = 1;
  while (y) {
    if (y & 1) (r *= x) %= mod;
    (x *= x) %= mod, y >>= 1;
  }
  return r;
}
void init() {
  scanf("%d%d%d%d", &N, &Y, &K, &X);
  for (int i = 1; i <= N; i++) scanf("%d", &V[i]);
  powk[0] = 1;
  for (int i = 1; i <= N; i++) powk[i] = 1LL * powk[i - 1] * K % Y;
  revk[0] = 1, revk[1] = powermod(K, Y - 2, Y);
  for (int i = 2; i <= N; i++) revk[i] = 1LL * revk[i - 1] * revk[1] % Y;
  for (int i = 1, u, v; i < N; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v), G[v].push_back(u);
  }
}
void calcu() {
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += 2LL * in[i] * (N - in[i]);
    ans += 2LL * out[i] * (N - out[i]);
    ans += 1LL * in[i] * (N - out[i]);
    ans += 1LL * (N - in[i]) * out[i];
  }
  ans = N * N * N - ans / 2;
  std::cout << ans;
}
int main() {
  init();
  solve(center(1));
  calcu();
  return 0;
}
