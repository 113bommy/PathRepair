#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 3;
const int MAXM = 2048 * 1024 + 3;
int t[MAXN];
int nas[MAXN];
int tree[MAXM];
int lazy[MAXM];
pair<int, int> zak[MAXN];
vector<int> vec[MAXN];
int ile = 0;
void DFS(int x) {
  zak[x].first = ile + 1;
  for (auto it : vec[x]) DFS(it);
  if (vec[x].empty()) ile++;
  zak[x].second = ile;
}
void zepchnij(int v) {
  tree[v * 2] += lazy[v];
  tree[v * 2 + 1] += lazy[v];
  lazy[v * 2] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}
void dodaj(int v, int x, int y, int a, int b, int war) {
  if (y < a || x > b) return;
  if (x >= a && y <= b) {
    tree[v] += war;
    lazy[v] += war;
    return;
  }
  zepchnij(v);
  dodaj(v * 2, x, (x + y) / 2, a, b, war);
  dodaj(v * 2 + 1, (x + y) / 2 + 1, y, a, b, war);
  tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}
int main() {
  int n, k;
  int pot = 1;
  scanf("%d %d", &n, &k);
  while (pot < n) pot *= 2;
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  t[n + 1] = MAXN;
  for (int i = n; i > 0; i--) {
    nas[i] = i + 1;
    while (t[i] >= t[nas[i]]) nas[i] = nas[nas[i]];
    vec[nas[i]].push_back(i);
  }
  DFS(n + 1);
  for (int i = 1; i <= k; i++) dodaj(1, 1, pot, zak[i].first, zak[i].second, 1);
  printf("%d ", tree[1]);
  for (int i = k + 1; i <= n; i++) {
    dodaj(1, 1, pot, zak[i - k].first, zak[i - k].second, -1);
    dodaj(1, 1, pot, zak[i].first, zak[i].second, 1);
    printf("%d ", tree[1]);
  }
  return 0;
}
