#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
const int maxn = 100005;
int ans;
int n;
int a[maxn * 2];
int main() {
  ans = INF;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 2; i <= n; i++) ans = min(ans, 1 + a[i] * a[i]);
  for (int i = 2; i <= n; i++) {
    int s = 0;
    for (int j = 0; j < 10001; j++) {
      s += a[i + j];
      if (abs(s) <= 10001) {
        ans = min(ans, s * s + (j + 1) * (j + 1));
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
