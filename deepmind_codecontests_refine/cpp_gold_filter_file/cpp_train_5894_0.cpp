#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
struct Tri {
  int ch[MAXN * 20][2], sz[MAXN * 40], rev[30];
  int tot;
  void init() {
    memset(ch, 0, sizeof(ch));
    memset(sz, 0, sizeof(sz));
    memset(rev, 0, sizeof(rev));
    tot = 2;
  }
  void insert(int x) {
    int u = 1;
    for (int i = 20; i >= 0; i--) {
      int p = (x >> i) & 1;
      p ^= rev[i];
      if (!ch[u][p]) ch[u][p] = tot++;
      sz[u]++;
      u = ch[u][p];
    }
    sz[u]++;
  }
  void Xor(int x) {
    for (int i = 20; i >= 0; i--) {
      int p = (x >> i) & 1;
      if (p) rev[i] ^= 1;
    }
  }
  void dfs(int i, int u, int &ret) {
    if (u == 0) return;
    int l, r;
    l = ch[u][0 ^ rev[i - 1]], r = ch[u][1 ^ rev[i - 1]];
    if (sz[l] < (1 << (i - 1))) {
      dfs(i - 1, l, ret);
    } else {
      ret = ret | (1 << (i - 1));
      dfs(i - 1, r, ret);
    }
  }
} T;
int a[MAXN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  n = unique(a + 1, a + 1 + n) - a - 1;
  T.init();
  for (int i = 1; i <= n; i++) {
    T.insert(a[i]);
  }
  while (m--) {
    int x, ret = 0;
    scanf("%d", &x);
    T.Xor(x);
    T.dfs(21, 1, ret);
    printf("%d\n", ret);
  }
  return 0;
}
