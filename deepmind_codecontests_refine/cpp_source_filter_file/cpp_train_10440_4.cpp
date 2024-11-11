#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int main() {
  int n, m, i, j;
  scanf("%d%d", &n, &m);
  int cnt = 0;
  if (m == 2 && n % 2 == 0 || n == 2 && m % 2 == 0)
    cnt = 2;
  else if (m == 2 && n % 2 == 1 || n == 2 && m % 2 == 1)
    cnt = 1;
  if (n == 1)
    printf("%d\n", m);
  else if (m == 1)
    printf("%d\n", n);
  else if ((m * n) % 2 == 0) {
    printf("%d\n", (n * m) / 2 + cnt);
  } else
    printf("%d\n", (n * m + 1) / 2 + cnt);
  return 0;
}
