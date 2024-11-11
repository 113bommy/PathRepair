#include <bits/stdc++.h>
using namespace std;
int n, a, b, k;
char s[200005];
int ans[200005], cnt;
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &k);
  scanf("%s", s + 1);
  s[n + 1] = '1';
  int last = 0;
  for (int i = 1; i <= n + 1; ++i) {
    if (s[i] == '1') {
      if (i - last <= b) {
        last = i;
        continue;
      }
      int j;
      for (j = last + b; j < i; j += b) {
        ans[++cnt] = j;
      }
      j -= b;
      if (i - 1 - j >= b) ans[++cnt] = i - 1;
      last = i;
    }
  }
  printf("%d\n", cnt - a + 1);
  for (int i = 1; i <= cnt - a + 1; ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
