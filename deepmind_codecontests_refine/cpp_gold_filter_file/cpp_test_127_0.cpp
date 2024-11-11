#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    string s, s1;
    cin >> s >> s1;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
      a[s[i] - 'a']++;
    }
    if (!(s1 == "abc" && a[0] && a[1] && a[2])) {
      cout << s << endl;
      continue;
    }
    int b, e;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'b') {
        b = i;
        break;
      }
    }
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == 'c') {
        e = i + 1;
        break;
      }
    }
    reverse(s.begin() + b, s.begin() + e);
    cout << s << endl;
  }
  return 0;
}
