#include <bits/stdc++.h>
using namespace std;
int fun(string s, int k) {
  int l = (int)s.size() + k;
  int mid = l / 2;
  if (mid > l - k) return l;
  int cnt = 0;
  for (int i = 0; i < mid && i < l - k; i++) {
    if (i + mid < l - k) {
      if (s[i] != s[i + mid]) return 0;
      cnt++;
    }
  }
  if (mid - cnt == k)
    return l;
  else
    return 0;
}
int main() {
  string s, tm;
  int k, l, ans, cnt;
  cin >> s;
  cin >> k;
  l = (int)s.size();
  tm = "";
  ans = 0;
  cnt = 0;
  for (int i = l - 1; i >= 0; i--) {
    tm += s[i];
    cnt++;
    if (cnt % 2 == k % 2) ans = max(ans, fun(tm, k));
  }
  for (int i = 0; i < 2; i++) {
    tm = "";
    cnt = 0;
    for (int j = i; j < l; j++) {
      tm += s[j];
      cnt++;
      if (cnt % 2 == 0) {
        int c = 0;
        for (int k = 0; k < cnt / 2; k++) {
          if (tm[k] != tm[k + cnt / 2]) break;
          c++;
        }
        if (c == cnt / 2) ans = max(ans, cnt);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
