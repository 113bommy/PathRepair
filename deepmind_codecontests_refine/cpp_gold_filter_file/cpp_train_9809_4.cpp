#include <bits/stdc++.h>
using namespace std;
char s[100010];
int b[100010];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, x;
    scanf("%d%d%s", &n, &x, s);
    bool has_x = x == 0;
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
      b[i] = b[i - 1] + (s[i - 1] == '0' ? 1 : -1);
      if (b[i] == x) has_x = true;
    }
    if (b[n] == 0) {
      printf("%d\n", has_x ? -1 : 0);
      continue;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if ((x - b[i]) % b[n] == 0 and (x - b[i]) / b[n] >= 0) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
}
