#include <bits/stdc++.h>
const int N = 1e3;
using namespace std;
int n, s;
bool ans[N + 5][N + 5], vis[N + 5];
struct vec {
  int val, id;
} a[N + 5];
bool cmp(vec a, vec b) { return a.val > b.val; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].val), a[i].id = i;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= a[i].val; j++)
      ans[(i + j - 2) % (n + 1) + 1][a[i].id] = 1;
  }
  s = n + 1;
  for (int i = 1; i <= n + 1; i++) {
    int sm = 0;
    for (int j = 1; j <= n; j++) sm += ans[i][j];
    if (!sm) s--, vis[i] = 1;
  }
  cout << s << endl;
  for (int i = 1; i <= n + 1; i++) {
    if (vis[i]) continue;
    for (int j = 1; j <= n; j++) printf("%d", ans[i][j]);
    printf("\n");
  }
  return 0;
}
