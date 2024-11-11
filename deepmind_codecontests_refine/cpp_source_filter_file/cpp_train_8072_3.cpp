#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005], ans, j, pointer1, pointer2, sum1, sum2, ans1, ans2;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], k += a[i];
  pointer1 = 1;
  pointer2 = n;
  while (sum1 + sum2 <= k) {
    if (sum1 >= sum2) {
      while (sum1 >= sum2) {
        if (sum1 + sum2 == k) {
          cout << ans1 << " " << ans2 << " ";
          return 0;
        }
        sum2 += a[pointer2];
        pointer2--;
        ans2++;
      }
    }
    if (sum1 <= sum2) {
      while (sum1 <= sum2) {
        if (sum1 + sum2 == k) {
          cout << ans1 << " " << ans2 << " ";
          return 0;
        }
        sum1 += a[pointer1];
        pointer1++;
        ans1++;
      }
    }
  }
}
