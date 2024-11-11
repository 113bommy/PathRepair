#include <bits/stdc++.h>
using namespace std;
const int N = 1503;
int a[N], x = 0, n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) x ^= (a[j] < a[i]);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int k = r - l + 1;
    x ^= ((k * (k - 1) / 2) & 1);
    if (x)
      puts("odd");
    else
      puts("even");
  }
  return 0;
}
