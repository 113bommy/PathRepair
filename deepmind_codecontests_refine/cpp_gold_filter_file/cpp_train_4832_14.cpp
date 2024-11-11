#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int arr[1000009], brr[1000009];
int main() {
  int test_case = 1;
  for (int cs = 1; cs <= test_case; cs++) {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 1000009;
    for (int i = 1; i <= n; i++)
      scanf("%d", &arr[i]), brr[arr[i]]++, ans = min(ans, arr[i]);
    if (ans > (k + 1)) ans = k + 1;
    for (int i = 1; i <= 1000009 - 9; i++) brr[i] += brr[i - 1];
    for (int i = k + 2; i <= 1000009 - 9; i++) {
      int cnt = 0;
      for (int j = i; j <= 1000009 - 9; j += i)
        cnt += brr[min(j + k, 1000009 - 9)] - brr[j - 1];
      if (cnt == n) ans = max(ans, i);
    }
    printf("%d\n", ans);
  }
  return 0;
}
