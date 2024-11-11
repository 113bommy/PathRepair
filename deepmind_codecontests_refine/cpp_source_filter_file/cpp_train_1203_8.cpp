#include <bits/stdc++.h>
using namespace std;
int mx = INT_MIN, i, ans, k;
string s;
int main() {
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' ||
        s[i] == 'Y' || s[i] == 'O')
      ans = 1;
    else
      ans++;
    mx = max(mx, ans);
  }
  cout << mx;
}
