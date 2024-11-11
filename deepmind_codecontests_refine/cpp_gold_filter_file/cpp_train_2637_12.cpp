#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, group;
  int cnt[5] = {0, 0, 0, 0, 0};
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &group);
    cnt[group]++;
  }
  int diff = min(cnt[3], cnt[1]);
  cnt[1] -= diff;
  cnt[3] -= diff;
  cnt[4] += diff;
  diff = min(cnt[2], (cnt[1] + 1) / 2);
  cnt[1] -= 2 * diff;
  cnt[2] -= diff;
  cnt[4] += diff;
  cnt[2] = (cnt[2] + 1) / 2;
  cnt[1] = (cnt[1] + 3) / 4;
  printf("%d", cnt[1] + cnt[2] + cnt[3] + cnt[4]);
  return 0;
}
