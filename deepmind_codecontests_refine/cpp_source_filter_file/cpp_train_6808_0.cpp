#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  string ans = "";
  int n = (int)(s).size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') ans += '0';
    if (s[i] == '-' && s[i + 1] == '-') ans += '2', i++;
    if (s[i] == '-' && s[i + 1] == '.') ans += '1', i++;
  }
  cout << ans;
}
