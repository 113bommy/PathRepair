#include <bits/stdc++.h>
using namespace std;
int cnt[6];
void init() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= 4; i++) cnt[i] = 0;
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    cnt[p]++;
  }
}
void work() {
  int ans = 0;
  while (cnt[1] != 0 || cnt[2] != 0) {
    if (cnt[1] != 0 && cnt[2] != 0) {
      cnt[1]--, cnt[2]--, cnt[3]++;
      ans++;
      continue;
    }
    if (cnt[2] != 0) {
      if (cnt[2] >= 3) {
        cnt[2] -= 3, cnt[3] += 2;
        ans += 2;
        continue;
      }
      if (cnt[2] >= 2) {
        cnt[2] -= 2, cnt[4]++, ans += 2;
        continue;
      }
      if (cnt[4] != 0) {
        cnt[2]--, cnt[4]--, cnt[3] += 2, ans++;
        continue;
      }
      if (cnt[3] >= 2) {
        cnt[3] -= 2, cnt[4] += 2, cnt[2]--;
        ans += 2;
        continue;
      }
    }
    if (cnt[1] != 0) {
      if (cnt[1] >= 3) {
        cnt[1] -= 3;
        cnt[3]++;
        ans += 2;
        continue;
      }
      if (cnt[4] >= 1 && cnt[1] == 2) {
        cnt[1] -= 2;
        cnt[3] += 2, cnt[4]--;
        ans += 2;
        continue;
      }
      if (cnt[3] >= 1) {
        cnt[4]++, cnt[3]--, cnt[1]--;
        ans++;
        continue;
      }
      if (cnt[4] >= 2 && cnt[1] == 1) {
        cnt[4] -= 2;
        cnt[3] += 3, cnt[1]--;
        ans += 2;
        continue;
      }
    }
    printf("-1\n");
    return;
  }
  printf("%d\n", ans);
  return;
}
int main() {
  init();
  work();
  return 0;
}
