#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dep[N], fa[N], co[N];
bool vis[N];
int main() {
  int T;
  for (scanf("%d", &T); T--;) {
    int n, d, s;
    scanf("%d%d", &n, &d), s = 0;
    for (int i = 1, x = n - 1; 1; i++) {
      if (x < (1 << i)) {
        s += i * x;
        break;
      }
      s += i * (1 << i), x -= 1 << i;
    }
    if (d < s) {
      puts("NO");
      continue;
    }
    s = n * (n - 1) / 2;
    if (d > s) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 1; i <= n; i++)
      fa[i] = i - 1, dep[i] = i - 1, vis[i] = 0, co[i] = 1;
    co[n] = 0;
    for (; d > s;) {
      int p, x = 0;
      for (int i = 1; i <= n; i++)
        if (!vis[i] && !co[i]) {
          p = i;
          break;
        }
      for (int i = 1; i <= n; i++)
        if (co[i] < 2 && dep[i] == dep[p] - 2) {
          x = i;
          break;
        }
      if (!x) {
        vis[x] = 1;
        continue;
      }
      co[fa[p]]--, co[x]++, dep[p]--, fa[p] = x, s--;
    }
    for (int i = 2; i <= n; i++) printf("%d ", fa[i]);
    puts("");
  }
}
