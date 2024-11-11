#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    ans += (y2 - y1 + 1) * (x2 - x1 + 1);
  }
  printf("%d ", ans);
}
