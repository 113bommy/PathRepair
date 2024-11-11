#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010], last[100010];
int x, y;
int main() {
  scanf("%d", &n);
  for (int i = (0), _b(100010); i < _b; ++i) last[i] = -1;
  for (int i = (0), _b(n); i < _b; ++i) {
    scanf("%d%d", &x, &y);
    int ans = 0;
    int j;
    for (j = 1; j * j < x; ++j)
      if (x % j == 0) {
        ans += (last[j] < i - y);
        last[j] = y;
        ans += (last[x / j] < i - y);
        last[x / j] = y;
      }
    if (x % j == 0) {
      ans += (last[j] < i - y);
      last[j] = y;
    }
    printf("%d\n", ans);
  }
  return 0;
}
