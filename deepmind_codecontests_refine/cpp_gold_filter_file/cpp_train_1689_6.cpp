#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, l, tl, f;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    l = s1.length();
    int a[26] = {0};
    for (int i = 0; i < l; i++) {
      a[s1[i] - 'a']++;
    }
    int b[26];
    for (int i = 0; i < 26; i++) {
      b[i] = a[i];
    }
    tl = l;
    f = 0;
    if (l > s2.length()) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < s2.length() - l + 1; i++) {
      for (int j = i; j < i + l; j++) {
        if (b[s2[j] - 'a'] > 0) {
          tl--;
          b[s2[j] - 'a']--;
        } else {
          break;
        }
      }
      if (tl == 0) {
        f = 1;
        break;
      } else {
        tl = l;
        for (int j = 0; j < 26; j++) {
          b[j] = a[j];
        }
      }
    }
    if (f == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
