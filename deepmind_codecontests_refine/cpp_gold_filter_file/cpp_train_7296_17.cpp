#include <bits/stdc++.h>
using namespace std;
int p[110];
int n, m;
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) {
    printf("1\n");
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res == 0) return 0;
    if (res == -1) p[i] = 1;
    if (res == 1) p[i] = -1;
  }
  int cnt = 0;
  int l = 1, r = m;
  while (l < r) {
    int mid = (l + r) >> 1;
    printf("%d\n", mid);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res == 0) return 0;
    res *= p[cnt];
    cnt++;
    if (cnt >= n) cnt = 0;
    if (res < 0)
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d\n", l);
  return 0;
}
