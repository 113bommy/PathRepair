#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    map<int, int> mp;
    string s;
    cin >> s;
    int temp = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '+')
        temp++;
      else
        temp--;
      if (mp[temp] == 0) mp[temp] = i + 1;
    }
    int ans = 0;
    for (int i = 0;; i++) {
      if (mp[-i - 1] != 0)
        ans += mp[-i - 1];
      else {
        ans += s.size();
        break;
      }
    }
    cout << ans << "\n";
  }
}
