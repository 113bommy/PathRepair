#include <bits/stdc++.h>
using namespace std;
int a[3], sum[3];
int main() {
  int n, t, x, y;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &t, &x, &y);
    a[t] += x;
    sum[t] += 10;
  }
  for (int i = 1; i < 3; i++) {
    bool live = false;
    if (sum[i] % 2 == 0) {
      if (a[i] >= sum[i] / 2) live = true;
    } else {
      if (a[i] > sum[i] / 2) live = true;
    }
    if (live)
      printf("LIVE\n");
    else
      printf("DEAD\n");
  }
  return 0;
}
