#include <bits/stdc++.h>
using namespace std;
int arr[15][15];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    ans += x / 10;
    arr[x % 10][x / 10]++;
  }
  for (int i = 9; i >= 0; i--)
    for (int j = 0; j < 10; j++)
      if (k <= arr[i][j] * (10 - i)) {
        ans += k / (10 - i);
        printf("%d\n", ans);
        return 0;
      } else {
        ans += arr[i][j];
        arr[0][j + 1] += arr[i][j];
        k -= arr[i][j] * (10 - i);
      }
  printf("%d\n", ans);
}
