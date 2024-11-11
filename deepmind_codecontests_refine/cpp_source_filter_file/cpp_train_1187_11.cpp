#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int a[maxn], n;
int cnt[5];
int main() {
  while (~scanf("%d", &n)) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    int ans = 0;
    if (cnt[1] == cnt[2]) {
      cout << cnt[1] << endl;
      continue;
    }
    if (cnt[1] > cnt[2]) {
      ans += cnt[2];
      cnt[1] -= cnt[2];
      cnt[3] += cnt[2];
      cnt[2] = 0;
      ans += cnt[1] / 3 * 2;
      cnt[3] += cnt[1] / 3;
      cnt[1] = cnt[1] % 3;
      if (cnt[1] == 1) {
        if (cnt[3] >= 1) {
          ans++;
          cnt[3] -= 1;
          cnt[1] -= 1;
          cnt[4] += 1;
        } else if (cnt[4] >= 2) {
          ans += 2;
          cnt[4] -= 2;
          cnt[1] = 0;
          cnt[3] += 1;
        } else {
          puts("-1");
          continue;
        }
      } else if (cnt[1] == 2) {
        if (cnt[4] >= 1) {
          ans += 2;
          cnt[4] -= 1;
          cnt[1] = 0;
          cnt[3] += 1;
        } else if (cnt[3] >= 2) {
          ans += 2;
          cnt[3] -= 2;
          cnt[1] = 0;
          cnt[4] += 2;
        } else {
          puts("-1");
          continue;
        }
      }
    } else if (cnt[1] < cnt[2]) {
      ans += cnt[1];
      cnt[2] -= cnt[1];
      cnt[3] += cnt[1];
      cnt[1] = 0;
      ans += cnt[2] / 3 * 2;
      cnt[3] += cnt[2] / 3;
      cnt[2] = cnt[2] % 3;
      if (cnt[2] == 1) {
        if (cnt[4] >= 1) {
          ans++;
          cnt[4] -= 1;
          cnt[2] = 0;
          cnt[3] += 1;
        } else if (cnt[3] >= 2) {
          ans += 2;
          cnt[3] -= 2;
          cnt[4] += 2;
          cnt[2] = 0;
        } else {
          puts("-1");
          continue;
        }
      } else if (cnt[2] == 2) {
        ans += 2;
        cnt[2] = 0;
        cnt[4] += 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
