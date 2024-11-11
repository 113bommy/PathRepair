#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char sa[N], sb[N];
int To[N << 1], Ne[N << 1], St[2333], prt[N << 1][2], ans;
bool vi[2333];
inline __attribute__((always_inline)) void addedge(int u, int v) {
  static int en = 0;
  To[++en] = v, Ne[en] = St[u], St[u] = en;
  To[++en] = u, Ne[en] = St[v], St[v] = en;
}
void dfs(int u) {
  vi[u] = 1;
  for (int i = St[u]; i; i = Ne[i]) {
    if (!vi[To[i]]) {
      dfs(To[i]);
      prt[++ans][0] = u, prt[ans][1] = To[i];
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s%s", sa + 1, sb + 1);
  for (int i = 1; i <= n; ++i) {
    if (sa[i] != sb[i]) {
      addedge(sa[i], sb[i]);
    }
  }
  for (int i = 'a'; i <= 'z'; ++i)
    if (!vi[i]) dfs(i);
  printf("%d\n", ans);
  for (int i = 1; i <= ans; ++i) {
    printf("%c %c\n", prt[i][0], prt[i][1]);
  }
  return 0;
}
