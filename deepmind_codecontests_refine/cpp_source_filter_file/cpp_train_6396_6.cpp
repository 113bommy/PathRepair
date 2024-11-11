#include <bits/stdc++.h>
using namespace std;
int num[1000];
int ans, mx, n;
void dfs(int a, int b) {
  if (a <= 0 || b > n) return;
  int tmp = 0;
  int x = num[a];
  while (num[a] == x) tmp++, a--;
  while (num[b] == x) tmp++, b--;
  if (tmp >= 3) ans += tmp, dfs(a, b);
}
int main(void) {
  int k, x, a, b, i;
  scanf("%d%d%d", &n, &k, &x);
  for (i = 1; i <= n; i++) scanf("%d", &num[i]);
  mx = 0;
  for (i = 1; i <= n; i++) {
    if (num[i] == x && num[i + 1] == x) {
      a = i - 1;
      b = i;
      ans = 1;
      while (num[b] == x) ans++, b++;
      dfs(a, b);
      if (ans > mx) mx = ans;
    }
  }
  printf("%d\n", mx);
  return 0;
}
