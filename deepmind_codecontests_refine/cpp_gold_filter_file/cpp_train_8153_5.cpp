#include <bits/stdc++.h>
using namespace std;
int num[100020], nxt[100020];
struct point {
  int st, en, num;
} pnt[100020 * 4];
int max1(int a, int b) {
  if (a > b) return a;
  return b;
}
int main() {
  int n, sum = 0, cnt = 0, besti, min1 = 1 << 25, tmp, i;
  scanf("%d", &n);
  num[n + 1] = nxt[0] = num[0] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &num[i]), nxt[i] = i;
  }
  for (i = 0; i < 100020 * 3; i++) pnt[i].st = pnt[i].en = pnt[i].num = 0;
  for (i = 1; i <= n + 1; i++) {
    if (num[i] >= num[i - 1]) {
      sum += num[i] - num[i - 1];
    } else {
      besti = i - 1;
      while (num[besti] > num[i]) {
        tmp = max1(num[nxt[besti] - 1], num[i]);
        pnt[cnt].en = i - 1;
        pnt[cnt].st = nxt[besti], pnt[cnt++].num = num[besti] - tmp;
        nxt[i] = nxt[besti];
        besti = nxt[besti] - 1;
      }
      if (num[besti] >= num[i]) nxt[i] = nxt[besti];
    }
  }
  printf("%d\n", sum);
  for (i = 0; i < cnt; i++) {
    for (int j = 0; j < pnt[i].num; j++)
      printf("%d %d\n", pnt[i].st, pnt[i].en);
  }
  return 0;
}
