#include <bits/stdc++.h>
using namespace std;
const int maxn = 300015;
int a[maxn];
int node[600000 * 22][2];
int tot = 1;
void build(int x) {
  int u = 0;
  for (int i = 20; i >= 0; i--) {
    int g = (x >> i) & 1;
    if (!node[u][g]) node[u][g] = tot++;
    u = node[u][g];
  }
}
int query(int k) {
  int u = 0, ans = 0;
  for (int i = 20; i >= 0; i--) {
    int g = (k >> i) & 1;
    if (!node[u][g]) {
      g = 1 ^ g;
    }
    ans += (g << i);
    u = node[u][g];
  }
  return ans;
}
bool vis[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    vis[a[i]] = 1;
  }
  for (int i = 0; i <= 600000; i++)
    if (!vis[i]) build(i);
  int g = 0;
  while (m--) {
    int k;
    scanf("%d", &k);
    g = g ^ k;
    printf("%d\n", query(g) ^ g);
  }
  return 0;
}
