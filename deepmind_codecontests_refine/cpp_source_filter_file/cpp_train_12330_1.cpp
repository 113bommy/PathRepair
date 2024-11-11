#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 * int(1e5) + 5;
int tn, tcase = 0;
int n, m, k;
int ans[100001];
char opt[100001];
int id[100001];
bool vis[100001];
int main() {
  scanf("%d %d", &n, &m);
  int cur = 0;
  for (int i = 1; i <= m; ++i) scanf("%*c%c%d", &opt[i], &id[i]);
  for (int i = 1; i <= m; ++i) {
    if (opt[i] == '+') vis[id[i]] = true;
    if (opt[i] == '-' && !vis[id[i]]) {
      vis[id[i]] = true;
      cur++;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (opt[i] == '+') {
      if (i - 1 && id[i] != id[i - 1] || cur) ans[id[i]] = 1;
      cur++;
    } else {
      cur--;
      if (i < m - 1 && id[i] != id[i + 1] || cur) ans[id[i]] = 1;
    }
  }
  int num = 0;
  for (int i = 1; i <= n; ++i)
    if (!ans[i]) num++;
  printf("%d\n", num);
  for (int i = 1; i <= n; ++i)
    if (!ans[i]) printf("%d  ", i);
  return 0;
}
