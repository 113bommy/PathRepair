#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (i % n == 0 && i > 3) {
      for (int j = 1; j < 2; j++)
        if (s[i - j] == s[i - j - 1] && s[i - j] == s[i - j - 2]) {
          ans++;
          break;
        }
    }
  }
  cout << ans << endl;
  return 0;
}
