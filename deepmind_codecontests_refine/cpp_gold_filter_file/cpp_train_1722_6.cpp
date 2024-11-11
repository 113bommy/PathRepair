#include <bits/stdc++.h>
using namespace std;
int lagbe[1003], ace[1003], n, magic;
int ok(int x) {
  int magicP = magic;
  for (int i = 0; i < n; i++) {
    if (lagbe[i] * x > ace[i] + magicP) return 0;
    int need = lagbe[i] * x - ace[i];
    if (need > 0) magicP -= need;
    if (magicP < 0) return 0;
  }
  return 1;
}
int bs() {
  int lo = 0, hi = 10000;
  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    if (ok(mid) == 0)
      hi = mid - 1;
    else
      lo = mid;
  }
  return lo;
}
int main() {
  scanf("%d %d", &n, &magic);
  for (int i = 0; i < n; i++) scanf("%d", &lagbe[i]);
  for (int i = 0; i < n; i++) scanf("%d", &ace[i]);
  cout << bs() << endl;
  return 0;
}
