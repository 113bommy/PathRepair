#include <bits/stdc++.h>
using namespace std;
int amount, winter_tires;
int air_temp[200005];
int min_connect[200005], mem = 0;
void solve() {
  int res = 0, pre = 0;
  for (int i = 1; i <= amount; i++) {
    if (air_temp[i] >= 0) continue;
    if (!pre)
      pre = i;
    else
      min_connect[++mem] = i - pre - 1, pre = i;
    winter_tires--, res += 2;
  }
  if (winter_tires < 0) {
    printf("-1");
    return;
  }
  sort(min_connect + 1, min_connect + mem + 1);
  for (int i = 1; i <= mem; i++)
    if (min_connect[i] <= winter_tires)
      res -= 2, winter_tires -= min_connect[i];
  if (pre && winter_tires >= amount - pre) res--;
  printf("%d", res);
}
int main() {
  scanf("%d %d", &amount, &winter_tires);
  for (int i = 1; i <= amount; i++) scanf("%d", &air_temp[i]);
  solve();
}
