#include <bits/stdc++.h>
int max(int a, int b) { return a < b ? b : a; }
int r, h;
int main() {
  while (~scanf("%d%d", &r, &h)) {
    int ans = h / r * 2;
    h = h - h / r * r;
    if (h * 2 < r)
      ans++;
    else if ((h * 2.0) >= (sqrt(3) * r))
      ans += 3;
    else
      ans += 2;
    printf("%d\n", ans);
  }
  return 0;
}
