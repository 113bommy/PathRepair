#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 100;
struct Node {
  string pref, suff;
  bool incr = false;
  int len = 0;
  void push_front(char ch) {
    if (!len)
      incr = false;
    else if (ch != pref[0])
      incr = (ch < pref[0]);
    len++;
    if (suff.size() < 2) suff = ch + suff;
    pref = ch + pref;
    if (pref.size() > 6) pref.pop_back();
  }
} ans[N];
string s;
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  for (int i = s.size() - 1; i >= 0; i--) {
    char ch = s[i];
    if (i + 1 < s.size() && s[i] == s[i + 1]) {
      ans[i] = ans[i + 2];
      if (ans[i].len != 0 &&
          (ch < ans[i].pref[0] || ch == ans[i].pref[0] && ans[i].incr)) {
        ans[i].push_front(ch);
        ans[i].push_front(ch);
      }
    } else {
      ans[i] = ans[i + 1];
      ans[i].push_front(ch);
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (ans[i].len <= 10)
      cout << ans[i].len << ' ' << ans[i].pref << endl;
    else
      cout << ans[i].len << ' ' << ans[i].pref.substr(0, 5) << "..."
           << ans[i].suff << endl;
  }
  return 0;
}
