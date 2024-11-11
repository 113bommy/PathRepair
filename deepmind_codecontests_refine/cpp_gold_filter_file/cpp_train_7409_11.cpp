#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 13;
int a[N], n, d, cnt;
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 2; i <= n; ++i) {
    int tmp = a[i - 1] - a[i], cc;
    if (tmp >= 0) cc = tmp / d + 1, a[i] += cc * d, cnt += cc;
  }
  printf("%d\n", cnt);
  return 0;
}
