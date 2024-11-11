#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int arr[5009];
unordered_map<int, int> brr, crr;
int ans[5009];
int main() {
  int test_case = 1;
  for (int cs = 1; cs <= test_case; cs++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
      int val = 1;
      int a1 = abs(arr[i]);
      for (int j = 2; j * j <= a1; j++) {
        int a = 0;
        while (a1 % j == 0) a++, a1 /= j;
        if (a & 1) val *= j;
      }
      if (arr[i] < 1) a1 = -a1;
      arr[i] = val * a1;
    }
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      int cnt1 = 0;
      for (int j = i; j <= n; j++) {
        if (arr[j] == 0)
          cnt1 = min(1, cnt1 + 1);
        else {
          int a = brr[arr[j]];
          if (a < i) cnt++;
          brr[arr[j]] = j;
        }
        ans[cnt + cnt1]++;
      }
      for (int j = n; j >= i; j--) brr[arr[j]] = 0;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
