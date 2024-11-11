#include <bits/stdc++.h>
using namespace std;
struct node {
  int num;
  int fl;
} x[110];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int k, f;
  int a = -1;
  for (int i = 0; i < m; i++) scanf("%d%d", &x[i].num, &x[i].fl);
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    int j;
    for (j = 0; j < m; j++) {
      int temp = x[j].num / i;
      if (x[j].num % i) temp++;
      if (temp != x[j].fl) break;
    }
    if (j == m) {
      int res = n / i + (n % i > 0 ? 1 : 0);
      if (ans != -1 && ans != res) {
        printf("-1\n");
        return 0;
      }
      ans = res;
    }
  }
  printf("%d\n", ans);
}
