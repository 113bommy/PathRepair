#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, speed[101], ram[101], hdd[101], cost[101];
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d%d", &speed[i], &ram[i], &hdd[i], &cost[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (speed[i] < speed[j] && ram[i] < ram[j] && hdd[i] < hdd[j]) {
        cost[i] = 1001;
      }
    }
  }
  printf("%u\n", min_element(cost + 1, cost + 1 + n) - cost);
  return 0;
}
