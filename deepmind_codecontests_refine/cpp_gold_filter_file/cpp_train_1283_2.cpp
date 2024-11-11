#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, allpo, num;
int a[N], cr[N], po[N], cri[N];
bool tr[N], fa[N], vis[N];
bool check(int x) { return cr[x] + allpo - po[x] == m; }
int main() {
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] > 0)
      ++cr[a[i]];
    else
      ++po[-a[i]];
  }
  for (register int i = 1; i <= n; ++i) allpo += po[i];
  int flag = 0;
  for (int i = 1; i <= n; ++i)
    if (check(i)) cri[++flag] = i;
  if (flag == 1) {
    for (int i = 1; i <= n; ++i)
      if (a[i] == cri[1] || (a[i] < 0 && a[i] != -cri[1]))
        puts("Truth");
      else
        puts("Lie");
  } else {
    for (int i = 1; i <= n; ++i) {
      if (a[i] > 0) {
        if (check(a[i]))
          puts("Not defined");
        else
          puts("Lie");
      } else {
        if (check(-a[i]))
          puts("Not defined");
        else
          puts("Truth");
      }
    }
  }
  return 0;
}
