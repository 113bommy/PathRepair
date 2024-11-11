#include <bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
struct cmp {
  bool operator()(int a, int b) { return a < b; }
};
priority_queue<int, vector<int>, cmp> s;
int main() {
  int n, m, i, j, x, shu, res = 0, cnt = 1;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &x);
    if (b[x] == 0) {
      b[x] = cnt;
      a[cnt++] = 1;
    } else {
      a[b[x]]++;
    }
  }
  if (n > m) {
    printf("0\n");
    return 0;
  }
  for (i = 1; i <= m; i++) {
    shu = 0;
    for (j = 0; j < m; j++) {
      shu += a[j] / i;
    }
    if (shu >= n)
      res = i;
    else
      break;
  }
  printf("%d\n", res);
}
