#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 1e3;
struct Player {
  int a, b;
} player[MAXN];
int n, m;
int sa[MAXN];
long long ans[MAXN];
void init() { memset(ans, 0, sizeof(ans)); }
bool cmp(int a, int b) {
  return player[a].a - player[a].b < player[b].a - player[b].b;
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &player[i].a, &player[i].b);
    sa[i] = i;
  }
  sort(sa, sa + n, cmp);
  long long suma = 0, sumb = 0;
  for (int i = 0; i < n; i++) {
    ans[sa[i]] += suma + 1ll * player[sa[i]].b * i;
    suma += player[sa[i]].a;
  }
  for (int i = 0; i < n; i++) {
    ans[sa[n - i - 1]] += sumb + 1ll * player[sa[n - i - 1]].a * i;
    sumb += player[sa[n - i - 1]].b;
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    int V = min(player[u].a + player[v].b, player[u].b + player[v].a);
    ans[u] -= V;
    ans[v] -= V;
  }
  for (int i = 0; i < n; i++) {
    printf("%I64d%c", ans[i], " \n"[i == n - 1]);
  }
  return 0;
}
