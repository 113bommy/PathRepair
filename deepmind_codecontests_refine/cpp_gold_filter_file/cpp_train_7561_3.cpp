#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int maxn = 3e5 + 5;
const int maxm = 4e5 + 10;
const int mod = 1e9 + 7;
int tot = 0;
int tree[maxn * 32][2];
int num[maxn * 32];
int val[maxn * 32];
int a[maxn];
void init() {
  tot = 1;
  tree[0][1] = tree[0][0] = 0;
}
void update(int x, int d) {
  int u = 0;
  for (int i = 30; i >= 0; i--) {
    int v = (x >> i) & 1;
    if (!tree[u][v]) {
      tree[tot][0] = tree[tot][1] = 0;
      tree[u][v] = tot;
      num[tot++] = 0;
    }
    u = tree[u][v];
    num[u] += d;
  }
  val[u] = x;
}
int query(int x) {
  int u = 0;
  for (int i = 30; i >= 0; i--) {
    int v = (x >> i) & 1;
    if (tree[u][v] && num[tree[u][v]] > 0)
      u = tree[u][v];
    else
      u = tree[u][v ^ 1];
  }
  return val[u] ^ x;
}
int main() {
  init();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    update(x, 1);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", query(a[i]));
    update(query(a[i]) ^ a[i], -1);
  }
  return 0;
}
