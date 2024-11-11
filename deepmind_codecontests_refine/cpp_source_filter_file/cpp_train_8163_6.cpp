#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int q, x, y, s = 0, d = 0;
  bool arr[1002];
  char ans[1000003];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i == j) {
        scanf("%d", &arr[i]);
        s += arr[i];
      } else
        scanf("%d", &x);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &x);
    if (x == 1 || x == 2) {
      scanf("%d", &y);
      y--;
      if (arr[y] == 1)
        s -= 1;
      else
        s += 1;
      arr[y] = !arr[y];
    } else
      ans[d++] = s % 2 + '0';
  }
  printf("%s", ans);
  return 0;
}
