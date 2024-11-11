#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, cnt, min_add, max_add;
char s[105];
int ans;
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (2 * n); i++) {
    scanf("%s", s);
    m = strlen(s);
    for (int j = (0); j < (m); j++) {
      if (s[j] == '.') {
        x = j;
        break;
      }
    }
    y = 0;
    for (int j = (x + 1); j < (m); j++) {
      y *= 10;
      y += s[j] - 48;
    }
    if (y == 0) cnt++;
    ans -= y;
  }
  min_add = max(0, n - cnt);
  max_add = min(n, 2 * n - cnt);
  int best = -1, tmp;
  for (int i = (min_add); i <= (max_add); i++) {
    tmp = ans + i * 1000;
    if (abs(tmp) <= best || best == -1) best = abs(tmp);
  }
  printf("%.3lf\n", (double)best / 1000.0);
  return 0;
}
