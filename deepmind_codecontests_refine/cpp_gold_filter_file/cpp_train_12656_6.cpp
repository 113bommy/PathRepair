#include <bits/stdc++.h>
using namespace std;
struct node {
  int ini, fim, s, sum;
};
int n, n1, n2, n3, v[100010];
node SEG[4 * 100010];
void build(int id, int i, int j) {
  SEG[id].ini = i;
  SEG[id].fim = j;
  SEG[id].sum = 0;
  SEG[id].s = 0;
  if (i == j) return;
  int m = (i + j) / 2;
  build(2 * id, i, m);
  build(2 * id + 1, m + 1, j);
}
void update(int id, int i, int val) {
  if (SEG[id].ini > i || SEG[id].fim < i) return;
  if (SEG[id].ini == SEG[id].fim) {
    SEG[id].sum = val;
    SEG[id].s = val;
    return;
  }
  update(2 * id, i, val);
  update(2 * id + 1, i, val);
  SEG[id].sum = SEG[2 * id].sum + SEG[2 * id + 1].sum;
  SEG[id].s = max(SEG[2 * id + 1].s, SEG[2 * id + 1].sum + SEG[2 * id].s);
}
int bs(int id, int val) {
  if (SEG[id].ini == SEG[id].fim) return SEG[id].ini;
  if (SEG[2 * id + 1].s >= val) return bs(2 * id + 1, val);
  return bs(2 * id, val - SEG[2 * id + 1].sum);
}
int main() {
  scanf("%d", &n);
  build(1, 1, n);
  for (int g = 0; g < n; g++) {
    scanf("%d %d", &n1, &n2);
    update(1, n1, ((n2 == 0) ? -1 : 1));
    if (n2 == 1) scanf("%d", &v[n1]);
    if (SEG[1].s <= 0)
      printf("-1\n");
    else
      printf("%d\n", v[bs(1, 1)]);
  }
}
