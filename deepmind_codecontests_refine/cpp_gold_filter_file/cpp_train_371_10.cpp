#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1600];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x;
    char y;
    scanf("%d %c", &x, &y);
    int ans = 1, tail = 1, last = x;
    if (s[1] != y) last--;
    for (int j = 1; j < n; j++) {
      while ((last || s[tail + 1] == y) && tail < n) {
        tail++;
        if (s[tail] == y) continue;
        last--;
      }
      ans = max(ans, tail - j + 1);
      if (s[j] != y) last++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
