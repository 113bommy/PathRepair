#include <bits/stdc++.h>
using namespace std;
int num[2][100005];
int main() {
  int n, p1, p2;
  long long sum1 = 0, sum2 = 0;
  scanf("%d", &n);
  p1 = p2 = n - 1;
  for (int i = 0; i < n; i++) scanf("%d", &num[0][i]);
  for (int i = 0; i < n; i++) scanf("%d", &num[1][i]);
  sort(num[0], num[0] + n);
  sort(num[1], num[1] + n);
  for (int i = 1; i <= n; i++) {
    if (p1 >= 0 && p2 >= 0) {
      if (num[0][p1] > num[1][p2]) {
        sum1 += num[0][p1];
        p1--;
      } else
        p2--;
    } else {
      if (p1 == -1)
        p2--;
      else {
        sum1 += num[0][p1];
        p1--;
      }
    }
    if (p1 >= 0 && p2 >= 0) {
      if (num[0][p1] < num[1][p2]) {
        sum2 += num[1][p2];
        p2--;
      } else
        p1--;
    } else {
      if (p2 == -1)
        p1--;
      else {
        sum2 += num[0][p2];
        p2--;
      }
    }
  }
  printf("%lld\n", sum1 - sum2);
  return 0;
}
