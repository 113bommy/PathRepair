#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, A = 1e6 + 2;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int k;
  string s;
  cin >> k >> s;
  int next_1[(int)s.size() + 2];
  for (int i = (int)s.size() - 1; i >= 0; i--) {
    if (s[i] == '1')
      next_1[i] = i;
    else
      next_1[i] = (i == (int)s.size() - 1 ? -1 : next_1[i + 1]);
  }
  int ans = 0, lst = -1, used = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (k == 0) {
      if (s[i] == '1')
        lst = i;
      else
        ans += i - lst;
    } else {
      if (s[i] == '1') used++;
      if (used < k) continue;
      if (used > k) lst = (~lst ? next_1[lst + 1] : next_1[0]), used--;
      ans += next_1[lst + 1] - lst;
    }
  }
  cout << ans;
  return 0;
}
