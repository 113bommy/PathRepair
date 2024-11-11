#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, p, x, y;
  scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
  int sum = 0;
  int num[1111];
  int large = 0;
  for (int i = 0; i < k; i++) {
    int tmp;
    scanf("%d", &tmp);
    num[i] = tmp;
    if (tmp >= y) large++;
    sum += tmp;
  }
  int needlarge = max((n + 1) / 2 - large, 0);
  if (sum + needlarge * y + (n - k - needlarge) > x || needlarge > n - k)
    puts("-1");
  else {
    for (int i = 0; i < needlarge; i++) printf("%d ", y);
    for (int i = 0; i < n - k - needlarge; i++) printf("1 ");
    puts("");
  }
}
