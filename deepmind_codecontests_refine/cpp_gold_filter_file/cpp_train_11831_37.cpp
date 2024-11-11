#include <bits/stdc++.h>
using namespace std;
int ans;
string s;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9')
      ans++;
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i')
      ans++;
  }
  cout << ans;
  return 0;
}
