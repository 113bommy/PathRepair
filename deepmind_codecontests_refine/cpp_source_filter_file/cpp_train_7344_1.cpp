#include <bits/stdc++.h>
using namespace std;
int n, b, d, c, ans;
int main() {
  scanf("%d %d %d", &n, &b, &d);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    if (x > b) continue;
    c += x;
    if (c >= d) c = 0, ans++;
  }
  printf("%d\n", ans);
  return 0;
}
