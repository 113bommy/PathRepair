#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[100010];
  cin >> n >> k;
  if (n / 2 > k)
    printf("-1\n");
  else {
    if (n == 1) {
      if (k == 0)
        printf("1\n");
      else
        printf("-1\n");
    } else {
      int t = k - (n / 2 - 1);
      printf("%d %d ", t, 2 * t);
      int cnt = 1;
      for (int i = 1; i < n / 2; i++) {
        printf(" %d %d ", 900000000 + cnt, 900000000 + cnt + 1);
        cnt += 2;
      }
      if (n % 2) printf("1000000000");
    }
  }
}
