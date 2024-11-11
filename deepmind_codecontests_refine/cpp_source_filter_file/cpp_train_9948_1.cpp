#include <bits/stdc++.h>
using namespace std;
struct str {
  int v, nex;
} edge[101000];
int mark[1010000], sz[50100], sou[50100], f[50100][2], fst[50100];
vector<int> vec[1010000];
int n, m, T, e;
void make_edge(int a, int b) {
  edge[++e].nex = fst[a];
  fst[a] = e;
  edge[e].v = b;
}
bool solve() {
  for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = 0;
  for (int i = 1; i <= T; i++) {
    mark[i] = (abs(rand() * rand() + rand()) % (2) + 1);
    for (int j = 0; j < (int)vec[i].size(); j++) f[vec[i][j]][mark[i]] = i;
  }
  int ans = 0;
  for (int u = 1; u <= n; u++) {
    if (!f[u][0] && !f[u][1]) return false;
    if (!f[u][0]) {
      sou[u] = 1;
      for (int i = fst[u]; i; i = edge[i].nex)
        if (sou[edge[i].v] == 0) ans++;
    } else if (!f[u][1]) {
      sou[u] = 0;
      for (int i = fst[u]; i; i = edge[i].nex)
        if (sou[edge[i].v] == 1) ans++;
    } else {
      int cnt[2] = {0, 0};
      for (int i = fst[u]; i; i = edge[i].nex) cnt[sou[edge[i].v]]++;
      if (cnt[0] > cnt[1])
        ans += cnt[0], sou[u] = 1;
      else
        ans += cnt[1], sou[u] = 0;
    }
  }
  if (ans < (m + 1) / 2) return false;
  for (int i = 1; i <= n; i++) printf("%d ", f[i][sou[i]]);
  putchar('\n');
  for (int i = 1; i <= T; i++) printf("%d ", mark[i]);
  return true;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) swap(a, b);
    make_edge(b, a);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &sz[i]);
    for (int j = 1; j <= sz[i]; j++) {
      int k;
      scanf("%d", &k);
      vec[k].push_back(i);
      T = max(T, k);
    }
  }
  while (!solve())
    ;
  return 0;
}
