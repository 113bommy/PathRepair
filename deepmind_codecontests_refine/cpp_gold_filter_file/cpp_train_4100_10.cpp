#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct node {
  int k, a;
  int num;
} lcm[N];
int n;
int cmp(struct node a, struct node b) { return a.k < b.k; }
int main() {
  int i;
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &lcm[i].k, &lcm[i].a);
      lcm[i].num = 0;
    }
    sort(lcm + 1, lcm + n + 1, cmp);
    int tmp = 0;
    lcm[1].num = lcm[1].a;
    if (n == 1) {
      int ans = lcm[1].k;
      {
        int tp = 4;
        ans++;
        while (lcm[1].num - tp > 0) {
          tp = tp << 2;
          ans++;
        }
        printf("%d\n", ans);
      }
      continue;
    }
    for (i = 2; i <= n; i++) {
      int tp = lcm[i].k - lcm[i - 1].k;
      tp *= 2;
      if (tp > 31) {
        lcm[i].num = lcm[i].a;
        continue;
      }
      int tpp = 1 << tp;
      tmp = lcm[i - 1].num % tpp;
      if (tmp) tmp = 1;
      tmp += lcm[i - 1].num / tpp;
      lcm[i].num = tmp;
      lcm[i].num = (lcm[i].num - lcm[i].a) > 0 ? lcm[i].num : lcm[i].a;
    }
    int ans = lcm[n].k;
    if (lcm[n].num >= 1) {
      ans++;
      int tp = 4;
      while (lcm[n].num - tp > 0) {
        tp = tp << 2;
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
