#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, ans, f[200005];
char s[11];
int find(int k) {
  if (k == f[k]) return k;
  return f[k] = find(f[k]);
}
void add(int x, int y) {
  if (find(x) != find(y)) f[find(x)] = find(y);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= 2 * n + 3; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%s", &x, &y, s);
    x -= y;
    y = min(x + 2 * y, 2 * n - x - 2 * y + 2);
    x = max(x, -x);
    if (s[0] == 'x') {
      add(2 * y, 2 * x);
      add(2 * y + 1, 2 * x + 1);
    } else {
      add(2 * y + 1, 2 * x);
      add(2 * x + 1, 2 * y);
    }
  }
  for (int i = 0; i <= n + 1; i++)
    if (find(2 * i) == find(2 * i + 1)) {
      printf("0");
      return 0;
    }
  int s = 0;
  for (int i = 0; i <= 2 * n + 3; i++) s += (find(i) == i);
  s = s / 2 - 2;
  ans = 1;
  for (int i = 1; i <= s; i++) ans = ans * 2 % 1000000007;
  printf("%d", ans);
}
