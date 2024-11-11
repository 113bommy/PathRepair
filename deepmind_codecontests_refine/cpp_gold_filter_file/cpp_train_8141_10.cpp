#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  string s;
  while (T--) {
    cin >> s;
    int len = s.length();
    int ans = 0;
    for (int i = 2; i < len; i++) {
      if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o' &&
          s[i + 1] == 'n' && s[i + 2] == 'e') {
        ans++;
        a[ans] = i;
        s[i] = '0';
      } else if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o') {
        ans++;
        a[ans] = i - 1;
        s[i - 1] = '0';
      } else if (s[i - 2] == 'o' && s[i - 1] == 'n' && s[i] == 'e') {
        ans++;
        a[ans] = i - 1;
        s[i - 1] = '0';
      }
    }
    cout << ans << "\n";
    for (int i = 1; i <= ans; i++) {
      if (i > 1) {
        cout << " ";
      }
      cout << a[i] + 1;
    }
    cout << "\n";
  }
  return 0;
}
