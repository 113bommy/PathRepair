#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000;
const int MOD = 1e9 + 7;
int doFor(int m, int n, int k) {
  printf("%d\n", 2 * n + 1);
  printf("%d %d ", m, -m - 1);
  for (int i = 1; i < n - 1; ++i) printf("%d %d ", 1, -1);
  printf("1 -1 %d", k + 1);
}
int searchFor(int p, int to) {
  int ret = (to + p - 1) / p;
  if (ret > MAX_N) return ret;
  while (ret <= MAX_N and p * ret - to <= ret) ++ret;
  return ret;
}
int main() {
  int h;
  scanf("%d", &h);
  for (int i = 3; i <= 1999; i += 2) {
    int k = searchFor(i, h);
    if (k > MAX_N or i * k - h > MAX_N) continue;
    int m = i * k - h;
    if (i == 3)
      printf("3\n%d %d %d\n", m, -m - 1, k + 1);
    else
      doFor(m, (i - 1) / 2, k);
    break;
  }
  return 0;
}
