#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
struct node {
  int u, v;
} e[500005];
int n, m, k, fa[500005], tot;
long long p[500005], w[500005], ans;
map<long long, int> mp;
vector<int> v[500005 * 2];
void makeSet(int x) {
  for (int i = 1; i <= x; i++) fa[i] = i;
}
int findSet(int x) {
  if (fa[x] != x) fa[x] = findSet(fa[x]);
  return fa[x];
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  makeSet(n);
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % mod;
  for (int i = 1; i <= n; i++) scanf("%lld", &w[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &e[i].u, &e[i].v);
    long long t = w[e[i].u] ^ w[e[i].v];
    if (!mp[t]) mp[t] = ++tot;
    ++tot;
    v[mp[t]].push_back(i);
  }
  ans = 1ll * ((1ll << k) - tot) % mod * p[n] % mod;
  for (int i = 1; i <= tot; i++) {
    int siz = n;
    for (int j = 0; j < v[i].size(); j++) {
      int tmp = v[i][j];
      int x = findSet(e[tmp].u), y = findSet(e[tmp].v);
      if (x != y) {
        fa[x] = y;
        siz--;
      }
    }
    ans = (ans + p[siz]) % mod;
    for (int j = 0; j < v[i].size(); j++) {
      int tmp = v[i][j];
      fa[e[tmp].u] = e[tmp].u;
      fa[e[tmp].v] = e[tmp].v;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
