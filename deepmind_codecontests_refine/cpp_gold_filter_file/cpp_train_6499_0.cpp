#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += a[i][i];
  int Q;
  scanf("%d", &Q);
  int x, y;
  for (int i = 0; i < Q; i++) {
    scanf("%d", &x);
    if (x == 3) printf("%d", ans & 1);
    if (x == 2 || x == 1) {
      scanf("%d", &y);
      ans++;
    }
  }
  puts("");
}
