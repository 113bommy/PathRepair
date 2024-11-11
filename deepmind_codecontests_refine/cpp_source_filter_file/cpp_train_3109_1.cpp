#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
int n, que[N];
char s[N], w[N];
int main() {
  scanf("%d %s %s", &n, s, w);
  if (strcmp(s, w) == 0) {
    puts("0");
    return 0;
  }
  int ans = 1;
  int qh = 0, qt = 0;
  int j = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (i == 0 || w[i] != w[i - 1]) {
      j = min(i, j);
      while (j >= 0 && s[j] != w[i]) {
        j--;
      }
      if (j < 0) {
        puts("-1");
        return 0;
      }
      while (qh < qt) {
        if (que[qh] + (qt - qh - 1) <= i) {
          break;
        }
        qh++;
      }
      if (i != j) {
        que[qt++] = j;
        ans = max(ans, qt - qh + 1);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
