#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
int a[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
    cnt += (i - 1) >> 1;
    if (cnt >= m) {
      a[i] += (cnt - m);
      for (int j = n, k = 1e9; j > i; j--, k -= i + 1) {
        a[j] = k;
      }
      for (int j = 1; j <= n; j++) {
        printf("%d ", a[j]);
      }
      return 0;
    }
  }
  puts("-1");
  return 0;
}
