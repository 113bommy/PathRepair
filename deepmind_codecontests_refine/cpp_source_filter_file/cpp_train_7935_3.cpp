#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, tot;
int a[N], b[N], t[N], co[N];
void solve() {
  int ans = 0;
  memset(co, 0, sizeof(co));
  memset(t, 0, sizeof(t));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 1; j <= tot; j++) {
      if (a[j] * a[j] > x) break;
      if (x % a[j]) continue;
      if (!t[a[j]]) t[a[j]] = ++ans;
      co[i] = ans;
      break;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) printf("%d ", co[i]);
  printf("\n");
}
int main() {
  for (int i = 2; i <= 1000; i++) {
    if (!b[i]) a[++tot] = i;
    for (int j = i * i; j <= 1000; j += i) b[j] = 1;
  }
  int T;
  for (scanf("%d", &T); T; T--) solve();
  return 0;
}
