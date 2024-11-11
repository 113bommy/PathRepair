#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int a[3][3] = {1, 7, 9, 3, 2, 5, 4, 8, 6};
int ans[550][550];
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 2) return printf("-1\n"), 0;
  int cnt = 1, tmp = n * n - 9;
  for (int i = n - 1; i >= 0; i--) {
    if (i % 2 == 0) {
      for (int j = n - 1; j >= 0; j--) {
        if (i < 3 && j < 3)
          ans[i][j] = a[i][j] + tmp;
        else
          ans[i][j] = cnt++;
      }
    } else {
      for (int j = 0; j < n; j++) {
        if (i < 3 && j < 3)
          ans[i][j] = a[i][j] + tmp;
        else
          ans[i][j] = cnt++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) printf("%d ", ans[i][j]);
    printf("\n");
  }
}
