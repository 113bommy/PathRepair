#include <bits/stdc++.h>
using namespace std;
struct bian {
  int i, len, flag, l, r;
} b[100010];
bool cmp1(bian x, bian y) {
  if (x.len == y.len) return x.flag > y.flag;
  return x.len < y.len;
}
bool cmp2(bian x, bian y) { return x.i < y.i; }
int main() {
  int n, m, temp = 1, temp2 = 2, temp3 = 3;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &b[i].len, &b[i].flag);
    b[i].i = i;
  }
  sort(b, b + m, cmp1);
  for (int i = 0; i < m; i++) {
    if (i == 0 && b[i].flag == 0) {
      printf("-1");
      return 0;
    }
    if (b[i].flag == 0 && i + 1 > (temp - 1) * (temp) / 2) {
      printf("-1");
      return 0;
    }
    if (b[i].flag == 1) {
      b[i].l = 1;
      b[i].r = temp + 1;
      temp++;
    } else {
      b[i].l = temp2;
      b[i].r = temp3;
      temp2++;
      if (temp2 >= temp3 - 1) {
        temp3++;
        temp2 = 2;
      }
    }
  }
  sort(b, b + m, cmp2);
  for (int i = 0; i < m; i++) printf("%d %d\n", b[i].l, b[i].r);
}
