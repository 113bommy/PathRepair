#include <bits/stdc++.h>
using namespace std;
int n, a, cnt[100010], cnt1, cnt2, num1, num2, ans;
map<int, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    if (cnt[a]) {
      mp[cnt[a]]--;
      if (mp[cnt[a]] == 0) {
        mp.erase(cnt[a]);
      }
    }
    cnt[a]++;
    mp[cnt[a]]++;
    if (mp.size() == 1) {
      if (mp.begin()->second == 1 || mp.begin()->first == 1) {
        ans = i;
      }
    } else if (mp.size() == 2) {
      for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (it == mp.begin()) {
          cnt1 = it->first;
          num1 = it->second;
        } else {
          cnt2 = it->first;
          num2 = it->second;
        }
      }
      if (num1 == 1) {
        if (cnt1 == 1 || cnt1 == cnt2 + 1) {
          ans = i;
        }
      } else if (num2 == 1) {
        if (cnt2 == 1 || cnt2 == cnt1 + 1) {
          ans = i;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
