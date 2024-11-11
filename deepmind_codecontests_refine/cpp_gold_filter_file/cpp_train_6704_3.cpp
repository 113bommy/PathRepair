#include <bits/stdc++.h>
using namespace std;
long long p[68];
long long fun(int id, long long ans) {
  long long i = 0, j = ans / (p[id] * 2) + 1;
  while (i != j && i + 1 != j) {
    long long mid = (i + j) / 2;
    if (ans / (2 * mid + 1) > mid - 1 &&
        (2 * mid + 1) * p[id] <= ans - (2 * mid + 1) * (mid - 1))
      i = mid;
    else
      j = mid;
  }
  if ((2 * i + 1) * p[id] == ans - (2 * i + 1) * (i - 1))
    return (2 * i + 1) * p[id];
  return -1;
}
int main() {
  long long n, tmp;
  int i;
  bool f = false;
  p[0] = 1;
  for (i = 1; i < 62; i++) p[i] = p[i - 1] * 2;
  scanf("%I64d", &n);
  for (i = 0; i < 62 && p[i] <= n + 1; i++) {
    tmp = fun(i, n);
    if (tmp != -1) {
      f = true;
      printf("%I64d\n", tmp);
    }
  }
  if (!f) printf("-1");
  return 0;
}
