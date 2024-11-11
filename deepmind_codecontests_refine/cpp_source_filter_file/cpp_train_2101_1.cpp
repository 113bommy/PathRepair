#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    int cnt1 = 0, cnt2 = 0;
    for (int i = t.size() - 1; i >= 0; i--) {
      if (t[i] != '0')
        break;
      else
        cnt1++;
    }
    reverse(s.begin(), s.end());
    int flag = 0, i;
    for (i = 0; i < s.size(); i++) {
      if (i < cnt1) {
        continue;
      }
      if (s[i] == '1') {
        cnt2 = i - cnt1;
        flag = 1;
        break;
      }
    }
    if (i <= cnt1) {
      cout << s.size() << endl;
      continue;
    }
    if (!flag) {
      cout << 1 << endl;
    } else
      cout << cnt2 << endl;
  }
  return 0;
}
