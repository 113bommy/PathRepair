#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
  int t1, t2, t3;
  t1 = k * l / nl;
  t2 = c / d;
  t3 = p / np;
  if (t1 >= t2) t1 = t2;
  if (t1 >= t3) t1 = t3;
  printf("%d\n", t1 / n);
  return 0;
}
