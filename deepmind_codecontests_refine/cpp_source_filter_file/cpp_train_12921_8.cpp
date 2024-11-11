#include <bits/stdc++.h>
const int N = 1e5;
bool used[2 * N];
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int l = 0;
  for (int i = 0; i < n; ++i) {
    int b;
    scanf("%d", &b);
    if (used[b]) {
      printf("0 ");
    } else {
      int cur_l;
      for (int j = l; j < n; ++j) {
        used[a[j]] = true;
        if (a[j] == b) {
          cur_l = j;
          break;
        }
      }
      printf("%d ", cur_l - l + 1);
      l = cur_l + 1;
    }
  }
  return 0;
}
