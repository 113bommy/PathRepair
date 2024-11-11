#include <bits/stdc++.h>
const int inf = (int)1e9;
using namespace std;
struct Hash {
  int h1, h2;
  long long h3;
  Hash() {}
  Hash(int h1, int h2, long long h3) : h1(h1), h2(h2), h3(h3) {}
  bool operator<(Hash o) const {
    return make_pair(make_pair(h1, h2), h3) <
           make_pair(make_pair(o.h1, o.h2), o.h3);
  }
  bool operator==(Hash o) const {
    return make_pair(make_pair(h1, h2), h3) ==
           make_pair(make_pair(o.h1, o.h2), o.h3);
  }
};
int n;
int c[300300], d[300300];
char ch[300300];
vector<int> g[300300];
int p1 = 31, p2 = 311, p3 = 91;
int mod1 = (int)1e9 + 7;
int mod2 = (int)1e9 + 9;
set<Hash> S[300300];
int maxi, cnt;
void dfs(int v, int p, int h1, int h2, long long h3) {
  int nh1 = (h1 * 1ll * p1 % mod1 + ch[v]) % mod1;
  int nh2 = (h2 * 1ll * p2 % mod2 + ch[v]) % mod2;
  long long nh3 = (h3 * 1ll * p3 + ch[v]);
  for (__typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); it++) {
    int to = *it;
    if (to == p) continue;
    dfs(to, v, nh1, nh2, nh3);
  }
  S[v].insert(Hash(nh1, nh2, nh3));
  for (__typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); it++) {
    int to = *it;
    if (to == p) continue;
    if ((int)S[to].size() > (int)S[v].size()) S[to].swap(S[v]);
    for (__typeof(S[to].begin()) it = S[to].begin(); it != S[to].end(); it++) {
      S[v].insert(*it);
    }
  }
  if ((int)S[v].size() + c[v] > maxi) {
    maxi = (int)S[v].size() + c[v];
    cnt = 1;
  } else if ((int)S[v].size() + c[v] == maxi) {
    cnt++;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  scanf("\n");
  for (int i = 1; i <= n; i++) {
    scanf("%c", &ch[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  maxi = 1, cnt = 1;
  dfs(1, -1, 0, 0, 0);
  printf("%d\n%d\n", maxi, cnt);
  return 0;
}
