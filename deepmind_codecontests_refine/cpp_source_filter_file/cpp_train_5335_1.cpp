#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    int left = 0, right = n - 1, flag = 0;
    long long int lsum = 0, rsum = 0, c = 0, sum1 = 0, sum2 = 0;
    while (1) {
      if (left > right) break;
      if (flag == 0) {
        lsum = 0;
        for (i = left; i <= right; i++) {
          lsum += arr[i];
          if (lsum > rsum) break;
        }
        sum1 += lsum;
        c++;
        left = i + 1;
        flag = 1;
      } else {
        rsum = 0;
        for (i = right; i >= left; i--) {
          rsum += arr[i];
          if (rsum > lsum) break;
        }
        sum2 += rsum;
        c++;
        right = i - 1;
        flag = 0;
      }
    }
    printf("%d %d %d\n", c, sum1, sum2);
  }
}
