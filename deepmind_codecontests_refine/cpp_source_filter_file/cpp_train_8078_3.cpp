#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
int a, b, x, y, x2, y2, n, ans;
int xl[110], yl[110];
bool check() {
  for (int i = 0; i < 2; i++) {
    swap(a, b);
    for (int i = 0; i < 2; i++) {
      swap(x, y);
      for (int i = 0; i < 2; i++) {
        swap(x2, y2);
        if (x + x2 <= a && y <= b && y2 <= b) return true;
      }
    }
  }
  return false;
}
int main() {
  scanf(" %d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    scanf(" %d %d", &xl[i], &yl[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      x = xl[i], y = yl[i];
      x2 = xl[j], y2 = yl[j];
      if (check()) ans = max(ans, x * y + x2 * y2);
    }
  }
  printf("%d\n", ans);
}
