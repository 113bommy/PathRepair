#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 3;
int n, q;
int arr[maxN][maxN];
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n - 1; ++i)
    for (int j = 0; j <= n - 1; ++j) scanf("%d", &arr[i][j]);
  int ans = 0;
  for (int i = 0; i <= n - 1; ++i) {
    for (int j = 0; j <= n - 1; ++j) {
      ans += arr[i][j] + arr[j][i];
      ans %= 2;
    }
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int a, b;
    scanf("%d", &a);
    if (a == 3)
      printf("%d", ans);
    else {
      scanf("%d", &b);
      ans = (ans + 1) % 2;
    }
  }
}
