#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t = 0, m = 0;
  scanf("%d", &n);
  int arr[n + 2];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 1; k <= n; k++) {
        if (arr[i - 1] + arr[j + 1] == arr[n - k]) {
          t = 1;
          m++;
          printf("%d %d %d", n - k + 1, i, j + 2);
          break;
        }
      }
      if (m > 0) break;
    }
    if (m > 0) break;
  }
  if (t == 0) printf("-1");
}
