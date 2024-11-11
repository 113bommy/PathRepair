#include <bits/stdc++.h>
using namespace std;
int n, a[1111], b[1111];
int cmp(int i, int j) { return a[i] < a[j]; }
int main(void) {
  scanf("%d", &n);
  for (int i = 0; (i) < (int)(n); (i)++) scanf("%d", &a[i]), b[i] = i;
  sort(b, b + n, cmp);
  printf("%d %d", a[b[0]] + 1, a[b[1]]);
  return 0;
}
