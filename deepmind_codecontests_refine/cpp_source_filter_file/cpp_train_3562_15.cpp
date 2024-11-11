#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
int n, k;
char s[maxn];
vector<int> reles[maxn];
int fa[maxn], sz[maxn];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (y == 0) swap(x, y);
  fa[y] = x;
  if (x != 0) sz[x] += sz[y];
}
int calc(int x) {
  int y = x > k ? x - k : x + k;
  x = find(x);
  y = find(y);
  if (x == 0 || y == 0) return sz[x + y];
  return min(sz[x], sz[y]);
}
int main() {
  scanf("%d", &n);
  scanf("%d", &k);
  scanf("%s", s + 1);
  for (int i = 1; i <= k; i++) {
    int sz, x;
    scanf("%d", &sz);
    for (int j = 1; j <= sz; j++) {
      scanf("%d", &x);
      reles[x].push_back(i);
    }
  }
  for (int i = 1; i <= k + k; i++) fa[i] = i;
  for (int i = k + 1; i <= k + k; i++) sz[i] = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (reles[i].size() == 0) {
    } else if (reles[i].size() == 1) {
      ans -= calc(reles[i][0]);
      if (s[i] == '1') {
        fa[find(reles[i][0]) + k] = 0;
      } else {
        fa[find(reles[i][0])] = 0;
      }
      ans += calc(reles[i][0]);
    } else {
      int x = reles[i][0], y = reles[i][1];
      if (s[i] == '1') {
        if (find(x) != find(y)) {
          ans -= calc(reles[i][0]);
          ans -= calc(reles[i][1]);
          merge(x, y);
          merge(x + k, y + k);
          ans += calc(x);
        }
      } else {
        if (find(x) != find(y + k)) {
          ans -= calc(x);
          ans -= calc(y + k);
          merge(x, y + k);
          merge(x + k, y);
          ans += calc(x);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
