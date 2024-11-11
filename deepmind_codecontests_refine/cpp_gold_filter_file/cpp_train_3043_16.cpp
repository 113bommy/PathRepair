#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int t, n, d, tot;
int fa[maxn], deep[maxn], chain[maxn];
bool v[maxn];
void clear() {
  tot = 0;
  memset(v, 0, sizeof(v));
  chain[0] = 1;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    clear();
    scanf("%d%d", &n, &d);
    for (int i = 2; i <= n; i++) {
      fa[i] = i / 2;
      deep[i] = deep[fa[i]] + 1;
      d -= deep[i];
      tot = max(tot, deep[i]);
    }
    if (d < 0) {
      puts("NO");
      continue;
    }
    int p = n;
    while (p) {
      chain[deep[p]] = p;
      v[p] = 1;
      p = fa[p];
    }
    for (int i = n; i >= 1; i--) {
      if (v[i]) continue;
      int mx = tot;
      while (deep[fa[i]] < mx && d) {
        fa[i] = chain[deep[fa[i]] + 1], deep[i] = deep[fa[i]] + 1;
        if (deep[i] > tot) chain[++tot] = i, v[i] = 1;
        d--;
      }
    }
    if (d) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 2; i <= n; i++) printf("%d ", fa[i]);
    puts("");
  }
  return 0;
}
