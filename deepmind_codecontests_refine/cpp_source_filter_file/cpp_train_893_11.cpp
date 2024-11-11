#include <bits/stdc++.h>
using namespace std;
int ans;
int cnt[10], cnt2[10];
int al[20], ar[20];
bool have;
long long l, r;
bool check() {
  for (int i = 1; i < 10; ++i) cnt2[i] = cnt[i];
  bool flag = 0;
  for (int i = 1; i < 10; ++i) {
    flag |= (i == 1 && cnt[i] > 1) || (i != 1 && cnt[i]);
  }
  if (flag && have) return 0;
  cnt2[0] = 18;
  for (int i = 1; i < 10; ++i) cnt2[0] -= cnt2[i];
  for (int i = 0; i < 18; ++i) {
    for (int j = al[i] + 1; j < ar[i]; ++j) {
      if (cnt2[j]) return 1;
    }
    if (al[i] == ar[i]) {
      if (!cnt2[al[i]]) return 0;
      cnt2[al[i]]--;
      continue;
    }
    if (cnt2[al[i]]) {
      bool flag = 0;
      cnt2[al[i]]--;
      for (int j = i + 1; j < 18; ++j) {
        for (int k = al[j] + 1; k < 10; ++k) {
          if (cnt2[k]) return 1;
        }
        if (cnt2[al[j]]) {
          cnt2[al[j]]--;
          continue;
        }
        for (int k = i; k < j; ++k) cnt2[al[k]]++;
        flag = 1;
        break;
      }
      if (!flag) return 1;
    }
    if (cnt2[ar[i]]) {
      bool flag = 0;
      cnt2[ar[i]]--;
      for (int j = i + 1; j < 18; ++j) {
        for (int k = 0; k < ar[j]; ++k) {
          if (cnt2[k]) return 1;
        }
        if (cnt2[ar[j]]) {
          cnt2[ar[j]]--;
          continue;
        }
        for (int k = i; k < j; ++k) cnt2[ar[k]]++;
        flag = 1;
        break;
      }
      if (!flag) return 1;
    }
    return 0;
  }
  return 1;
}
void go(int p, int st) {
  ans += check();
  if (p == 0) return;
  for (int i = st; i < 10; ++i) {
    cnt[i]++, go(p - 1, i), cnt[i]--;
  }
}
int main() {
  cin >> l >> r;
  if (l == r) {
    cout << 1;
    return 0;
  }
  if (r == (1e18)) {
    r--, ans++, have = 1;
  }
  for (int i = 17; i >= 0; --i) {
    al[i] = l % 10, l /= 10;
    ar[i] = r % 10, r /= 10;
  }
  go(18, 1);
  cout << ans;
}
