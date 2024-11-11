#include <bits/stdc++.h>
using namespace std;
int cnt[5];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 5; i++) cnt[i] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int ans = 0;
  int m12 = min(cnt[1], cnt[2]);
  cnt[3] += m12;
  cnt[1] -= m12;
  cnt[2] -= m12;
  ans += m12;
  if (cnt[1]) {
    ans += 2 * (cnt[1] / 3);
    cnt[3] += (cnt[1] / 3) * 3;
    cnt[1] -= (cnt[1] / 3) * 3;
    if (cnt[1] == 0) {
      cout << ans << endl;
    } else if (cnt[1] == 1) {
      if (cnt[3]) {
        cout << ans + 1 << endl;
      } else if (cnt[4] >= 2) {
        cout << ans + 2 << endl;
      } else {
        cout << -1 << endl;
      }
    } else {
      if (cnt[4] >= 1 || cnt[3] >= 2) {
        cout << ans + 2 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  } else {
    ans += 2 * (cnt[2] / 3);
    cnt[2] += (cnt[2] / 3) * 3;
    cnt[2] -= (cnt[2] / 3) * 3;
    if (cnt[2] == 0) {
      cout << ans << endl;
    } else if (cnt[2] == 1) {
      if (cnt[4]) {
        cout << ans + 1 << endl;
      } else if (cnt[3] >= 2) {
        cout << ans + 2 << endl;
      } else {
        cout << -1 << endl;
      }
    } else {
      cout << ans + 2 << endl;
    }
  }
}
