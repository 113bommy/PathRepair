#include <bits/stdc++.h>
using namespace std;
static int n, ans, pos, sz[100000 + 10];
static vector<int> G[100000 + 10];
static unsigned long long H[100000 + 10], p[100000 + 10], pi[100000 + 10];
static unordered_map<unsigned long long, int> cnt;
unsigned long long eval(int x, int fa = 0) {
  unsigned long long &r = H[x] = 0;
  sz[x] = 0;
  for (int v : G[x])
    if (v != fa) {
      r ^= eval(v, x);
      sz[x] += 1;
    }
  r = (r + 1) * p[sz[x]];
  cnt[r]++;
  return r;
}
inline void inc(unsigned long long x) { cnt[x]++; }
inline void dec(unsigned long long x) {
  cnt[x]--;
  if (!cnt[x]) cnt.erase(x);
}
void dfs(int x, int fa = 0) {
  if (cnt.size() > ans) {
    ans = cnt.size();
    pos = x;
  }
  unsigned long long cpyx = H[x];
  for (int v : G[x])
    if (v != fa) {
      unsigned long long cpyv = H[v];
      dec(H[x]);
      dec(H[v]);
      H[x] = ((((H[x] * pi[sz[x]]) - 1) ^ H[v]) + 1) * p[sz[x] - 1];
      H[v] = ((((H[v] * pi[sz[v]]) - 1) ^ H[x]) + 1) * p[sz[v] + 1];
      sz[x]--;
      sz[v]++;
      inc(H[x]);
      inc(H[v]);
      dfs(v, x);
      dec(H[x]);
      dec(H[v]);
      H[x] = cpyx;
      H[v] = cpyv;
      sz[x]++;
      sz[v]--;
      inc(H[x]);
      inc(H[v]);
    }
}
int main() {
  scanf("%d", &n);
  p[0] = 1;
  pi[0] = 1;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
    p[i] = p[i - 1] * 19260817ULL;
    pi[i] = pi[i - 1] * 7089841341079321457ULL;
  }
  eval(1);
  dfs(1);
  printf("%d\n", pos);
  fprintf(stderr, "ans = %d\n", ans);
  return 0;
}
