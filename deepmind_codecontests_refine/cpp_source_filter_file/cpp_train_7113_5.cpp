#include <bits/stdc++.h>
using namespace std;
int n, m;
int cal(int x) {
  long long sum = 0;
  long long tmp = m;
  sum += x;
  while (1) {
    sum += x / tmp;
    if (x / tmp == 0) break;
    tmp *= m;
    if (sum >= n) break;
  }
  if (sum >= n) return 1;
  return 0;
}
int main() {
  int i, j, tot, l, r, mid;
  while (scanf("%d%d", &n, &m) != EOF) {
    l = 0, r = 100000001;
    while (l < r) {
      mid = (l + r) / 2;
      if (cal(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", l);
  }
  return 0;
}
