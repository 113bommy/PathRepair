#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.size();
  int n;
  cin >> n;
  int ans = 0;
  string a;
  while (n--) {
    cin >> a;
    for (int i = 0; i <= len - 1; i++) {
      int l = 0, r = 0;
      while (s[i] == a[0] || s[i] == a[1]) {
        if (s[i] == s[0]) l++;
        if (s[i] == s[1]) r++;
        i++;
      }
      ans += min(l, r);
    }
  }
  cout << ans << endl;
}
