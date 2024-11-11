#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000 + 10;
int a[maxn];
int num[maxn], sz = 0, ans[maxn];
void add(int x) {
  num[x]++;
  if (num[x] == 1) sz++;
}
void sub(int x) {
  num[x]--;
  if (!num[x]) sz--;
}
int main() {
  int n, m, T;
  scanf("%d%d%d", &n, &m, &T);
  for (int i = 1; i <= n; i++) {
    int x, y, z;
    scanf("%d:%d:%d", &x, &y, &z);
    a[i] = 3600 * x + 60 * y + z;
  }
  int cnt = 0, ma = 0;
  for (int i = 1, j = 1, tot = 0; i <= n; i++) {
    while (a[j] + T - 1 <= a[i]) sub(ans[j]), j++, tot--;
    if (sz < m)
      ans[i] = ++cnt;
    else
      ans[i] = ans[i - 1];
    add(ans[i]);
    ma = max(ma, ++tot);
  }
  if (ma < m) {
    printf("No solution\n");
    return 0;
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}
