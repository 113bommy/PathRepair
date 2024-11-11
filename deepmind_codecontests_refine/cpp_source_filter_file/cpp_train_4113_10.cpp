#include <bits/stdc++.h>
using namespace std;
struct date {
  int i, j, val;
};
int n, i, j, x, k, sol[100010], fr[100010], ul = 0;
date coada[3 * 100010];
inline int abs(int x) {
  if (x < 0)
    return (-x);
  else
    return x;
}
inline int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
inline int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
bool cmp(const date &x, const date &y) { return (x.val > y.val); }
int main() {
  scanf("%d", &n);
  for (i = 2; i <= 2 * n; i++) {
    for (j = 1; j <= i - 1; j++) {
      scanf("%d", &x);
      ul++;
      coada[ul].val = x;
      coada[ul].i = i;
      coada[ul].j = j;
    }
  }
  sort(coada + 1, coada + ul + 1, cmp);
  for (i = 1; i <= ul; i++)
    if (fr[coada[i].i] == 0 && fr[coada[i].j] == 0) {
      sol[coada[i].i] = coada[i].j;
      sol[coada[i].j] = coada[i].i;
      fr[coada[i].i] = 1;
      fr[coada[i].j] = 1;
    }
  for (i = 1; i <= 2 * n; i++) printf("%d ", sol[i]);
  return 0;
}
