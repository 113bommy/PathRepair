#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;
int d[MAXN];
int fa[MAXN];
int n, m;
int getfa(int x) {
  if (fa[x] == x) return x;
  fa[x] = getfa(fa[x]);
}
int las;
int main() {
  cin >> n >> m;
  las = n;
  if (n == 1) {
    if (m == 1)
      printf("YES\n0\n");
    else if (m > 1)
      printf("NO\n");
    else {
      printf("YES\n");
      printf("1\n1 1\n");
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    d[u]++;
    d[v]++;
    if (u == v) {
      printf("NO\n");
      return 0;
    }
    u = getfa(u);
    v = getfa(v);
    if (u != v) {
      fa[u] = v;
      las--;
    } else {
      if (las != 1) {
        printf("NO\n");
        return 0;
      }
    }
  }
  bool flag = true;
  for (int i = 1; i <= n; i++)
    if (d[i] != 2) flag = false;
  if (las == 1 && flag) {
    printf("YES\n0\n");
    return 0;
  }
  bool achieve = true;
  for (int i = 1; i <= n; i++)
    if (d[i] > 2) achieve = false;
  if (!achieve)
    printf("NO\n");
  else {
    printf("YES\n%d\n", n - m);
    priority_queue<int> q;
    for (int i = 1; i < n - m; i++) {
      pair<int, int> pi;
      pi = make_pair(1000, 1000);
      for (int x = 1; x <= n; x++)
        if (d[x] < 2) {
          for (int y = x + 1; y <= n; y++)
            if (d[y] < 2 && getfa(x) != getfa(y)) {
              pair<int, int> tp = make_pair(x, y);
              if (tp < pi) pi = tp;
            }
        }
      printf("%d %d\n", pi.first, pi.second);
      d[pi.first]++;
      d[pi.second]++;
      int x = getfa(pi.first), y = getfa(pi.second);
      fa[x] = y;
    }
    int x = -1, y;
    for (int i = 1; i <= n; i++)
      if (d[i] == 1) {
        if (x == -1)
          x = i;
        else
          y = i;
      }
    printf("%d %d\n", x, y);
  }
  return 0;
}
