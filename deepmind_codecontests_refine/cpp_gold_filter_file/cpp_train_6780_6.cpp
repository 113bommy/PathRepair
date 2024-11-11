#include <bits/stdc++.h>
using namespace std;
int k, n, a, b;
string s, ans = "";
int main() {
  cin >> s >> k;
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '?')
      a++;
    else if (s[i] == '*')
      b++;
  }
  n -= (a + b);
  if (n > k) {
    if (n - (a + b) > k) {
      cout << "Impossible";
      return 0;
    }
    int cnt = k - (n - (a + b));
    for (int i = 0; i < s.size(); i++) {
      if (i + 1 < s.size() && (s[i + 1] == '*' || s[i + 1] == '?')) {
        if (cnt) {
          ans = ans + s[i];
          cnt--;
        }
        i++;
      } else
        ans = ans + s[i];
    }
  } else if (n == k) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '*' || s[i] == '?') continue;
      cout << s[i];
    }
    return 0;
  } else {
    if (b == 0) {
      cout << "Impossible";
      return 0;
    }
    int ok = 0;
    for (int i = 0; i < s.size(); i++) {
      if (!ok && i + 1 < s.size() && s[i + 1] == '*') {
        ans = ans + s[i];
        for (int j = 0; j < k - n; j++) ans = ans + s[i];
        ok = 1;
      } else if (s[i] == '*' || s[i] == '?')
        continue;
      else
        ans = ans + s[i];
    }
  }
  cout << ans;
}
