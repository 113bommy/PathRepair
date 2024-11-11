#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (~scanf("%d", &n)) {
    int a, sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      sum += a;
    }
    scanf("%d", &m);
    int l, r;
    int judge = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &l, &r);
      if (judge == -1) {
        if (sum >= l && sum <= r)
          judge = sum;
        else if (sum <= l)
          judge = l;
      }
    }
    printf("%d\n", judge);
  }
  return 0;
}
