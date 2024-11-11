#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cities[101] = {0};
  for (int i = 1; i <= m; i++) {
    int max = 0, can = -1;
    for (int j = 1; j <= n; j++) {
      int a;
      scanf("%d", &a);
      if (a > max) {
        max = a;
        can = j;
      }
    }
    cities[can]++;
  }
  int max = 0, ans = -1;
  for (int i = 1; i <= 100; i++) {
    if (cities[i] > max) {
      max = cities[i];
      ans = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
