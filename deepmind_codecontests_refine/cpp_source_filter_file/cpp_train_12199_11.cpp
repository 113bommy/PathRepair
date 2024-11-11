#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
string s;
string t;
int ans = 0;
int pre[20];
int suf[20];
int main() {
  cin >> s;
  cin >> t;
  int j = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == t[j]) {
      pre[j++] = i;
    }
  }
  j = t.length() - 1;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == t[j]) {
      suf[j--] = i;
    }
  }
  int ans = 0;
  int len = s.length();
  int len1 = t.length();
  ans = max(suf[0], len - pre[len1 - 1] - 1);
  for (int i = 0; i < len1 - 1; i++) {
    ans = max(ans, suf[i + 1] - pre[i] - 1);
  }
  cout << ans << endl;
  return 0;
}
