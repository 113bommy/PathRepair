#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d%d", &n, &x);
    int dif = 0;
    int sam = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == x) continue;
      dif += a[i] - x, sam++;
    }
    if (!dif) {
      if (!sam) {
        printf("0\n");
        continue;
      } else {
        printf("1\n");
        continue;
      }
    }
    if (sam < n) {
      printf("1\n");
      continue;
    }
    printf("2\n");
  }
  return 0;
}
