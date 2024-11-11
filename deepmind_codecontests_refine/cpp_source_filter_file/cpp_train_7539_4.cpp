#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size();
  int m = s2.size();
  int c1[26] = {0};
  int c2[26] = {0};
  for (int i = 0; i < n; i++) {
    c1[s1[i] - 'a']++;
  }
  for (int i = 0; i < m; i++) {
    c2[s1[i] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (c2[i]) {
      if (!c1[i]) {
        cout << -1;
        return 0;
      }
      ans += min(c1[i], c2[i]);
    }
  }
  cout << ans;
  return 0;
}
