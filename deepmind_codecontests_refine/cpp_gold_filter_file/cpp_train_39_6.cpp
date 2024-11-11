#include <bits/stdc++.h>
using namespace std;
vector<int> u[50];
int t, m, f[25][50], s[25];
long long n, ans[6], pw[20];
void init() {
  int tab[] = {0, 4, 7};
  for (int(i) = (0); (i) <= ((3) - 1); (i)++)
    for (int(j) = (0); (j) <= ((3) - 1); (j)++)
      for (int(k) = (0); (k) <= ((3) - 1); (k)++)
        for (int(x) = (0); (x) <= ((3) - 1); (x)++)
          for (int(y) = (0); (y) <= ((3) - 1); (y)++)
            for (int(z) = (0); (z) <= ((3) - 1); (z)++) {
              int now = tab[i] + tab[j] + tab[k] + tab[x] + tab[y] + tab[z];
              if (u[now].empty())
                u[now] = {tab[i], tab[j], tab[k], tab[x], tab[y], tab[z]};
            }
  pw[0] = 1;
  for (int(i) = (1); (i) <= (18); (i)++) pw[i] = pw[i - 1] * 10;
}
void dfs(int pos, int rem) {
  int now = rem * 10 + s[pos];
  if (now > 46) return;
  for (int(i) = (0); (i) <= ((5) - 1); (i)++) {
    int need = now - i;
    if (need < 0) continue;
    if (!u[need].empty() && f[pos + 1][i] == -1) {
      f[pos + 1][i] = rem;
      if (pos < m) dfs(pos + 1, i);
    }
  }
}
int main() {
  init();
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    m = 0;
    while (n) {
      s[++m] = n % 10;
      n /= 10;
    }
    reverse(s + 1, s + m + 1);
    memset(f, -1, sizeof(f));
    dfs(1, 0);
    if (f[m + 1][0] == -1) {
      puts("-1");
      continue;
    }
    memset(ans, 0, sizeof(ans));
    int x = 0;
    for (int(i) = (m + 1); (i) >= (2); (i)--) {
      int d = f[i][x] * 10 - x + s[i - 1];
      for (int(j) = (0); (j) <= ((6) - 1); (j)++)
        ans[j] += u[d][j] * pw[m + 1 - i];
      x = f[i][x];
    }
    for (int(i) = (0); (i) <= ((6) - 1); (i)++) printf("%lld ", ans[i]);
    puts("");
  }
}
