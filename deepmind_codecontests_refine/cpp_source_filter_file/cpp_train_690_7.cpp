#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x1, x2;
  scanf("%d%d%d", &n, &x1, &x2);
  vector<pair<int, int>> c(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i].first);
    c[i].second = i + 1;
  }
  sort(c.begin(), c.end());
  int min1 = 1e9, min2 = 1e9;
  int pos1, pos2;
  bool ans = false;
  for (int i = n - 1; i >= 0; i--) {
    int need1 = (x1 + c[i].first - 1) / c[i].first;
    int need2 = (x2 + c[i].first - 1) / c[i].first;
    if (need1 + min2 <= n - i) {
      ans = true;
      printf("Yes\n");
      printf("%d %d\n", need1, min2);
      for (int j = 0; j < need1; j++) {
        printf("%d ", c[i + j].second);
      }
      printf("\n");
      int pos = max(i + need1, pos2);
      for (int j = 0; j < min2; j++) printf("%d ", c[pos + j].second);
      printf("\n");
      break;
    }
    if (need2 + min1 <= n - i) {
      ans = true;
      printf("Yes\n");
      printf("%d %d\n", min1, need2);
      int pos = max(i + need2, pos2);
      for (int j = 0; j < min1; j++) {
        printf("%d ", c[pos + j].second);
      }
      printf("\n");
      for (int j = 0; j < need2; j++) {
        printf("%d ", c[i + j].second);
      }
      break;
    }
    if (n - i >= need1 && need1 < min1) {
      min1 = need1;
      pos1 = i;
    }
    if (n - i >= need2 && need2 < min2) {
      min2 = need2;
      pos2 = i;
    }
  }
  if (!ans) {
    printf("No\n");
  }
}
