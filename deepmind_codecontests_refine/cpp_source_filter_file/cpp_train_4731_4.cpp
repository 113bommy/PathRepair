#include <bits/stdc++.h>
using namespace std;
bool F[30];
int a[30], n;
bool b;
void dfs(int x);
void dfs2(int p, int i, int x, int tong) {
  if (tong == x) dfs(p + 1);
  if (b) return;
  for (int j = i; j >= 1; --j) {
    if (F[j] || a[j] == x - 1 || tong + a[j] > x) continue;
    F[j] = true;
    dfs2(p, j - 1, x, tong + a[j]);
    if (b) return;
    F[j] = false;
  }
}
void dfs(int x) {
  if (x == n + 1) {
    b = true;
    return;
  }
  dfs2(x, x - 1, a[x] - 1, 0);
}
int main() {
  if (0) {
    freopen("input.txt", "r", stdin);
  }
  scanf("%d\n", &n);
  b = false;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == n) b = true;
  }
  for (int i = 1; i <= n; ++i)
    if (a[i] == 2 || a[i] == n - 1 || !b) {
      puts("NO");
      return 0;
    }
  b = false;
  sort(a + 1, a + n + 1);
  if (n == 1) {
    puts("YES");
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    if (i != 1) {
      dfs(i);
      if (!b) {
        puts("NO");
        return 0;
      } else {
        puts("YES");
        return 0;
      }
    }
  return 0;
}
