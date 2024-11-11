#include <bits/stdc++.h>
using namespace std;
struct cz {
  int x, y, g, s;
} e[50010], t[50010];
int num = 0, G, S, fa[210], n, m;
bool del[210];
long long ans = 1e18;
bool cmp(cz a, cz b) { return a.g < b.g; }
int find(int x) {
  if (fa[x] != x) fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &G, &S);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &e[i].x, &e[i].y, &e[i].g, &e[i].s);
  }
  sort(e + 1, e + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    memset(del, 0, sizeof(del));
    int nowg = e[i].g;
    t[++num] = e[i];
    for (int i = num - 1; i >= 1; i--)
      if (t[i + 1].s < t[i].s)
        swap(t[i + 1], t[i]);
      else
        break;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= num; i++) {
      int x = find(t[i].x), y = find(t[i].y);
      if (x != y) {
        fa[x] = y;
      } else
        del[i] = 1;
    }
    for (int i = 1; i <= num; i++) {
      if (del[i]) {
        num--;
        for (int j = i; j <= num; j++) {
          t[j] = t[j + 1];
          del[j] = del[j + 1];
        }
      }
    }
    if (num == n - 1) ans = min(ans, 1ll * G * nowg + 1ll * S * t[num].s);
  }
  if (ans != 1e18)
    printf("%I64d", ans);
  else
    printf("-1");
}
