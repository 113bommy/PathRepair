#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[26] = {0};
    for (int i = 0; i < s.length(); i++) {
      a[s[i] - 'a']++;
    }
    int flag = 0;
    for (int i = 0; i < 26; i++) {
      if (a[i] != 0) flag++;
    }
    if (flag <= 1)
      cout << "-1\n";
    else {
      sort(s.begin(), s.end());
      cout << s << "\n";
    }
  }
  return 0;
}
