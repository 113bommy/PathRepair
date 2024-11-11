#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0, a, b, c, d;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ans += (c - a + 1) * (d - b + 1);
  }
  printf("%d", ans);
}
