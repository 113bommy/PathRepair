#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[300005];
int ans, tmp;
int cmp(int a, int b) { return a < b; }
void work() {
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n, cmp);
  ans = a[0];
  int flag;
  while (1) {
    flag = 1;
    for (int i = 0; i < n; i++) {
      tmp = a[i] / ans;
      if (tmp * ans + k >= a[i]) continue;
      ans = a[i] / (tmp + 1);
      flag = 0;
    }
    if (flag) break;
  }
  printf("%d\n", ans);
}
int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    work();
  }
  return 0;
}
