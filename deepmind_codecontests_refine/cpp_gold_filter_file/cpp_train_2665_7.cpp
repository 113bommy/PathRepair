#include <bits/stdc++.h>
using namespace std;
int n, k, x, y;
void gg() { fflush(stdout); }
bool check(int L, int R) {
  if (L < 1 || R > n) return 0;
  printf("1 %d %d\n", L, R), gg();
  char ch[10];
  scanf("%s", ch);
  return ch[0] == 'T';
}
int fnd(int L, int R) {
  if (L > R) return 0;
  for (int mid = (R + L) >> 1; L < R; mid = (R + L) >> 1)
    if (check(mid, mid + 1))
      R = mid;
    else
      L = mid + 1;
  return L;
}
int main() {
  scanf("%d%d", &n, &k);
  x = fnd(1, n);
  y = fnd(1, x - 1);
  if (!check(y, x)) y = fnd(x + 1, n);
  printf("2 %d %d\n", x, y);
  return 0;
}
