#include <bits/stdc++.h>
using namespace std;
int n, h, m, ans;
int a[100];
int get(int x) { return ((rand() << 15) + rand()) % x + 1; }
int main() {
  scanf("%d%d%d", &n, &h, &m);
  for (int i = 1; i <= n; i++) a[i] = h;
  for (int i = 1; i <= m; i++) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    for (int j = l; j <= r; j++) a[i] = min(a[i], x);
  }
  for (int i = 1; i <= n; i++) ans += a[i] * a[i];
  cout << ans << endl;
  return 0;
}
