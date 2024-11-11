#include <bits/stdc++.h>
using namespace std;
int n, m;
int t[107][107];
int mini;
int a;
int maxi;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    mini = 1000000009;
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a);
      if (a < mini) {
        mini = a;
      }
    }
    if (mini > maxi) maxi = mini;
  }
  printf("%d", maxi);
  return 0;
}
