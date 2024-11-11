#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct edge {
  int t, next;
} e[N << 1];
int n, cnt;
int head[N], kind[N], son[N][6];
void add(int u, int t) {
  e[++cnt].t = t;
  e[cnt].next = head[u];
  head[u] = cnt;
}
void dfs(int u, int fa) {
  int sum = 0;
  for (int i = 1; i <= 5; i++) son[u][i] = 0;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].t;
    if (v == fa) continue;
    dfs(v, u);
    son[u][kind[v]]++;
    sum++;
  }
  if (son[u][5] || son[u][4] || son[u][3] > 2)
    kind[u] = 5;
  else if (son[u][3] == 2)
    kind[u] = 4;
  else if (son[u][3] || son[u][2] || son[u][1] >= 3)
    kind[u] = 3;
  else if (son[u][1] == 2)
    kind[u] = 2;
  else
    kind[u] = 1;
  return;
}
int main() {
  srand((unsigned)time(NULL));
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  for (int i = 1; i <= 100; i++) {
    int ro = rand() % n + 1;
    dfs(ro, 0);
    if (kind[ro] <= 4) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
