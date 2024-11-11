#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (k == 2) {
    int ans = INT_MAX;
    string ans_s;
    for (int j = 0; j < k; j++) {
      string t;
      int tmp = 0;
      for (int i = 0; i < n; i++) {
        t.push_back(char('A' + ((j + i) & 1)));
        tmp += (s[i] != t[i]);
      }
      if (tmp < ans) {
        ans = tmp;
        ans_s = t;
      }
    }
    cout << ans << '\n';
    cout << ans_s;
  } else {
    s.push_back('$');
    int ans = 0;
    int lst = 0;
    for (int i = 1; i < n + 1; i++) {
      if (s[lst] != s[i]) {
        ans += (i - lst) >> 1;
        for (int j = 0; j < k; j++) {
          if (char('A' + j) == s[lst] || char('A' + j) == s[i]) {
          } else {
            for (int l = lst + 1; l < i; l += 2) {
              s[l] = (char)('A' + j);
            }
            break;
          }
        }
        lst = i;
      }
    }
    ans += (n - lst) >> 1;
    cout << ans << endl;
    cout << s.substr(0, n) << endl;
  }
  return 0;
}
