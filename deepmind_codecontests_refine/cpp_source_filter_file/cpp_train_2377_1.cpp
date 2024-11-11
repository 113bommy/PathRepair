#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b - 1 > n) return !puts("-1");
  if ((LL)a * b < n) return !puts("-1");
  int cur = 0, p = 0;
  while (cur + b < n) {
    cur += b;
    p ++;
    for (int i = 1; i <= b; i ++)
      printf("%d ", cur + 1 - i);
    if (a - (1 + p) + b + cur > n) break;
  }
  if (n - (a - p) == cur)
    for (int i = n - (a - p) + 1; i <= n; i ++) printf("%d ", i);
  else {
    for (int i = n - (a - (1 + p)); i > cur; i --) printf("%d ", i);
    for (int i = n - (a - (1 + p)) + 1; i <= n; i ++) printf("%d ", i);
  }
  puts("");
  return 0;
}
