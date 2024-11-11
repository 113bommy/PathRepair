#include <bits/stdc++.h>
using namespace std;
int i, n, g[8] = {}, r[1111], ans1[1111];
char ans2[1111];
vector<pair<int, int> > f;
void dfs(int x, int y) {
  if (y > n) {
    for (i = 1; i <= n; i++) printf("%d %c\n", ans1[i], ans2[i]);
    exit(0);
  }
  for (int t = 0; t < f.size(); t++)
    if (r[t] == 0) {
      if (f[t].first == x) {
        ans1[y] = t + 1;
        ans2[y] = '+';
        r[t] = 1;
        dfs(f[t].second, y + 1);
        r[t] = 0;
      } else if (f[t].second == x) {
        ans1[y] = t + 1;
        ans2[y] = '-';
        r[t] = 1;
        dfs(f[t].first, y + 1);
        r[t] = 0;
      }
    }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    f.push_back(make_pair(v1, v2));
    ++g[v1];
    ++g[v2];
  }
  int h = 0, t = -1;
  for (i = 0; i <= 6; i++)
    if (g[i] % 2) {
      h++;
      t = i;
    }
  if (t == -1) t = f[0].first;
  if (h > 2)
    puts("No solution");
  else
    dfs(t, 1);
  puts("No solution");
  return 0;
}
