#include <bits/stdc++.h>
using namespace std;
struct ox {
  int val, id;
  int clo;
} x[1000];
int cmp1(ox a, ox b) { return a.val < b.val; }
int cmp2(ox a, ox b) { return a.id < b.id; }
int main() {
  int i, j;
  int n, m;
  int a, b;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &x[i].val);
    x[i].id = i;
  }
  sort(x, x + n, cmp1);
  while (m--) scanf("%d%d", &a, &b);
  for (i = 0; i < n; i++) x[i].clo = i % 2;
  sort(x, x + n, cmp2);
  for (i = 0; i < n; i++) printf("%d ", x[i].clo);
  return 0;
}
