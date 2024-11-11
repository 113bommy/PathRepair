#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100005;
int r[MAXN];
vector<int> G[MAXN];
int par[MAXN << 1];
int find_root(int x) { return (x == par[x] ? x : par[x] = find_root(par[x])); }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (1); i < (n + 1); i++) scanf("%d", &r[i]), r[i] ^= 1;
  for (int i = (1); i < (m + 1); i++) {
    int num;
    scanf("%d", &num);
    for (int j = (0); j < (num); j++) {
      int k;
      scanf("%d", &k);
      G[k].push_back(i);
    }
  }
  for (int i = (0); i < ((m << 1) + 1); i++) par[i] = i;
  for (int i = (1); i < (n + 1); i++) {
    int u = G[i][0], v = G[i][1];
    par[find_root(2 * u)] = find_root((2 * v) ^ r[i]);
    par[find_root(2 * u + 1)] = find_root((2 * v + 1) ^ r[i]);
  }
  for (int i = (1); i < (n + 1); i++)
    if (find_root(2 * i) == find_root(2 * i + 1)) return 0 * puts("NO");
  puts("YES");
}
