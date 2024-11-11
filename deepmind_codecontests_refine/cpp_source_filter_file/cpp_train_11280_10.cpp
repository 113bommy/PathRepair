#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, k;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (k == 1) {
    int ans = 0;
    for (int i = 1; i <= n + m + 1; i += (n - 1)) ans++;
    printf("%d\n", ans);
    for (int d = 1, i = 1; i <= ans; i++, d += (n - 1))
      printf(i == 1 ? "%d" : " %d", d);
    printf("\n");
    return 0;
  }
  int d = n + m;
  int ans = 1;
  bool f = false;
  for (int i = 1; i <= d;) {
    if (!f) {
      ans += (k - 1);
      i += n - 1;
      f = true;
    } else {
      ans += 1;
      i++;
      f = false;
    }
  }
  printf("%d\n", ans);
  d = 1;
  printf("1");
  f = false;
  for (int i = 2; i <= ans;) {
    if (!f) {
      for (int j = 1; j <= k - 1 && i <= ans; j++) {
        printf(" %d", d);
        i++;
      }
      f = true;
      d += n - 1;
    } else {
      printf(" %d", d);
      d++;
      i++;
      f = false;
    }
  }
  printf("\n");
  return 0;
}
