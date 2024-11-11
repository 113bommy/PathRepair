#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 7;
int n, l, tot;
struct rec {
  int a, id;
  bool operator<(const rec &x) const { return a < x.a; }
} a[MAXN];
int ans[MAXN][MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].a);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    int p = (i + 1) % (n + 1);
    if (p == 0) p = 1;
    for (int cnt = 1; cnt <= n + 1; ++cnt) {
      p = p % (n + 1) + 1;
      ans[p][a[i].id] = 1;
      a[i].a--;
      if (a[i].a == 0) break;
    }
  }
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d", ans[i][j]);
    }
    puts("");
  }
  return 0;
}
