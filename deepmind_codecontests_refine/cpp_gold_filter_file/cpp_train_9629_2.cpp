#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int cor[maxn];
long long ans[maxn];
int sz[maxn];
int maxq[maxn];
long long valor[maxn];
vector<int> grafo[maxn];
long long contcor[maxn];
int ddepth[maxn];
void finds(int u, int p, int c = 1) {
  sz[u] = 1;
  ddepth[u] = c;
  for (auto k : grafo[u]) {
    if (k != p) {
      finds(k, u, c + 1);
      sz[u] += sz[k];
    }
  }
}
bitset<30> cnt[maxn];
vector<int>* ptg[maxn];
vector<pair<int, int>> queries[maxn];
void dfs(int u, int p, bool keep) {
  int maior = -1;
  int maxs = -1;
  for (auto k : grafo[u]) {
    if (k != p) {
      if (sz[k] > maxs) {
        maxs = sz[k];
        maior = k;
      }
    }
  }
  for (auto k : grafo[u]) {
    if (k != p && k != maior) dfs(k, u, 0);
  }
  if (maxs != -1) {
    dfs(maior, u, 1);
    ptg[u] = ptg[maior];
    ptg[u]->push_back(u);
    cnt[ddepth[u]][cor[u]].flip();
    for (auto k : grafo[u]) {
      if (k != p && k != maior) {
        for (auto k1 : (*ptg[k])) {
          cnt[ddepth[k1]][cor[k1]].flip();
          ptg[u]->push_back(k1);
        }
      }
    }
  } else {
    ptg[u] = new vector<int>();
    ptg[u]->push_back(u);
    cnt[ddepth[u]][cor[u]].flip();
  }
  for (int i = 0; i < queries[u].size(); i++) {
    ans[queries[u][i].second] = cnt[queries[u][i].first].count();
  }
  if (keep == 0) {
    for (auto k : (*ptg[u])) {
      cnt[ddepth[k]][cor[k]].flip();
    }
  }
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n - 1; i++) {
    int a;
    scanf("%d", &a);
    grafo[a].push_back(i + 1);
  }
  for (int i = 1; i <= n; i++) {
    char a;
    scanf(" %c", &a);
    cor[i] = a - 'a';
  }
  int tempo = 0;
  int qq = q;
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    queries[a].push_back({b, tempo++});
  }
  finds(1, -1);
  dfs(1, -1, 1);
  for (int i = 0; i < qq; i++) {
    if (ans[i] <= 1) {
      printf("Yes\n");
    } else
      printf("No\n");
  }
}
