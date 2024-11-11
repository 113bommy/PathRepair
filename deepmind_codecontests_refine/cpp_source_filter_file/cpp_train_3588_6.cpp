#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[30], b[20];
  int sum1[200];
  memset(sum1, 0, sizeof(sum1));
  int sum2[200];
  memset(sum2, 0, sizeof(sum2));
  scanf("%s %s", a, b);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    char c, d;
    scanf("%d %c %d %c", &x, &c, &y, &d);
    if (c == 'a') {
      if (sum2[y] == 1 && d == 'y') {
        printf("%s %d %d\n", b, y, x);
        sum2[y]++;
      } else if (d == 'r' && sum2[y] < 2) {
        printf("%s %d %d\n", b, y, x);
        sum2[y] += 2;
      } else
        sum2[y] += (d == 'y') ? 1 : 2;
    } else if (c == 'h') {
      if (sum1[y] == 1 && d == 'y') {
        printf("%s %d %d\n", a, y, x);
        sum1[y] += 1;
      } else if (d == 'r' && sum1[y] < 2) {
        printf("%s %d %d\n", a, y, x);
        sum1[y] += 2;
      } else
        sum1[y] += (d == 'y') ? 1 : 2;
    }
  }
  return 0;
}
