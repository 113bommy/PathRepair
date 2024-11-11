#include <bits/stdc++.h>
const int maxn = 100005;
int n, m;
int st[maxn];
int mark[maxn];
int a[maxn], b[maxn];
int p, s;
int Abs(int a) { return a < 0 ? -a : a; }
int main() {
  int i, j;
  while (scanf("%d%d", &n, &m) != EOF) {
    p = s = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &st[i]);
      if (st[i] > 0)
        p++;
      else
        s++;
    }
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (i = 1; i <= n; i++) {
      if (st[i] > 0)
        a[st[i]]++;
      else
        b[-st[i]]++;
    }
    int num = 0;
    memset(mark, 0, sizeof(mark));
    for (i = 1; i <= n; i++) {
      if (m == a[i] + s - b[i]) {
        mark[i] = 1;
        num++;
      }
    }
    for (i = 1; i <= n; i++) {
      int g = Abs(st[i]);
      if (st[i] > 0 && mark[g] && num > 1) {
        puts("Not defined");
      } else if (st[i] > 0 && mark[g] && num == 1) {
        printf("Truth");
      } else if (st[i] > 0 && mark[g] <= 0) {
        puts("Lie");
      } else if (st[i] < 0 && mark[g] <= 0) {
        puts("Truth");
      } else if (st[i] < 0 && mark[g] > 0 && num > 1) {
        puts("Not defined");
      } else if (st[i] < 0 && mark[g] > 0 && num == 1) {
        puts("Lie");
      }
    }
  }
  return 0;
}
