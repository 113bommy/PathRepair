#include <bits/stdc++.h>
using namespace std;
int test, k, n;
int cost[10][10], arr[7];
int main() {
  scanf("%d", &test);
  for (int tc = 1; tc <= test; tc++) {
    n = 0;
    scanf("%d", &k);
    for (int i = 0; i < 7; i++) {
      scanf("%d", &arr[i]);
      if (arr[i]) n++;
    }
    for (int i = 0; i < 7; i++) {
      int num = 0;
      for (int j = 1; j <= 7; j++) {
        int day = (i + j) % 7;
        if (arr[day]) num++;
        cost[i][j] = num;
      }
    }
    long long ans = 0;
    k--;
    if (n <= k) {
      ans += (k / n) * 7;
      k %= n;
    }
    k++;
    for (int i = 1; i <= 7; i++) {
      bool IsTrue = false;
      for (int j = 0; j < 7; j++) {
        if (k > 0 && cost[j][i] >= k) {
          ans += i;
          IsTrue = true;
          break;
        }
      }
      if (IsTrue) break;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
