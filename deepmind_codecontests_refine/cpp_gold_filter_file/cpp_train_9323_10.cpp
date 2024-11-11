#include <bits/stdc++.h>
using namespace std;
int n, a, b, k;
char str[200100];
int cnt = 0;
int ans[200100];
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &k);
  scanf("%s", str + 1);
  int ship_cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '0') {
      cnt++;
      if (cnt == b) {
        ship_cnt++;
        ans[ship_cnt] = i;
        cnt = 0;
      }
    } else if (str[i] == '1')
      cnt = 0;
  }
  printf("%d\n", ship_cnt - a + 1);
  for (int i = 1; i <= ship_cnt - a + 1; i++) {
    printf("%d", ans[i]);
    if (i != ship_cnt) printf(" ");
  }
  return 0;
}
