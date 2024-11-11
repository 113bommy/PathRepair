#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int low = 0, upp = 0;
  for (int i = 0; i < s.length(); i++) {
    if (isupper(s[i])) low++;
  }
  int ans = low;
  for (int i = 0; i < s.length(); i++) {
    if (isupper(s[i])) low--;
    if (islower(s[i])) upp++;
    if (upp + low < ans) ans = upp + low;
  }
  cout << ans << endl;
  return 0;
}
