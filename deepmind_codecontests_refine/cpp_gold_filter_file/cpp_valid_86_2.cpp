#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] + s2[i] == '0' + '1') {
        ans += 2;
      } else if (s1[i] == '1') {
        if (i != s1.size() - 1 && s1[i + 1] == '0' && s2[i + 1] == '0') {
          ans += 2;
          i++;
        }
      } else if (s1[i] == '0') {
        if (i != s1.size() - 1 && s1[i + 1] == '1' && s2[i + 1] == '1') {
          ans += 2;
          i++;
        } else {
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
}
