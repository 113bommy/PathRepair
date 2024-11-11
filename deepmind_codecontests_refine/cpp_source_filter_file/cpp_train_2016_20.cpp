#include <bits/stdc++.h>
using namespace std;
int a[25], wz[25];
int n, p;
bool ok;
bool cho[25];
void dfs(int w, int xo, int num) {
  if (w > a[0]) return;
  if (ok) return;
  dfs(w + 1, xo, num);
  if (ok) return;
  cho[w] = 1;
  xo ^= a[w];
  if (a[w] <= 9)
    num = (num * 10 + a[w]) % p;
  else
    num = (num * 100 + a[w]) % p;
  if (xo == 0 && num == 0) {
    ok = 1;
    puts("Yes");
    int tot = 0;
    for (int i = 1; i <= w; i++)
      if (cho[i]) tot++;
    printf("%d\n", tot);
    for (int i = 1; i <= w; i++)
      if (cho[i]) printf("%d ", wz[i]);
    return;
  }
  dfs(w + 1, xo, num);
  cho[w] = 0;
}
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x <= 22) {
      a[++a[0]] = x;
      wz[a[0]] = i;
    }
  }
  dfs(1, 0, 0);
  if (!ok) puts("No");
  return 0;
}
