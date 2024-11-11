#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
int val[maxn], n, vis[maxn];
vector<int> son[maxn];
inline int id(char c) {
  if (c == 'A') return -1;
  if (c == 'I') return 0;
  if (c == 'X') return -3;
  if (c == 'O') return -2;
  if (c == 'N') return -4;
  return -4;
}
void Set(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int v : son[u]) Set(v);
}
int cal(int u) {
  if (val[u] >= 0) return val[u];
  if (val[u] == -4) return !cal(son[u][0]);
  int x = cal(son[u][0]), y = cal(son[u][1]);
  if (val[u] == -1) {
    if (x == 0) Set(son[u][1]);
    if (y == 0) Set(son[u][0]);
    return x & y;
  } else if (val[u] == -2) {
    if (x == 1) Set(son[u][1]);
    if (y == 1) Set(son[u][0]);
    return x & y;
  } else
    return x ^ y;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char op[10];
    scanf("%s", op);
    if (id(op[0])) {
      val[i] = id(op[0]);
      if (val[i] == -4) {
        int x;
        scanf("%d", &x);
        son[i].push_back(x);
        continue;
      }
      int x, y;
      scanf("%d", &x);
      scanf("%d", &y);
      son[i].push_back(x);
      son[i].push_back(y);
    } else {
      int x;
      scanf("%d", &x);
      val[i] = x;
    }
  }
  int ans = cal(1);
  for (int i = 1; i <= n; i++) {
    if (val[i] < 0) continue;
    if (vis[i])
      printf("%d", ans);
    else
      printf("%d", !ans);
  }
  puts("");
  return 0;
}
