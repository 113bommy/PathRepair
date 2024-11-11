#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e5 + 5;
bool isv(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, ss;
  cin >> s >> ss;
  if (s.length() == ss.length()) {
    long long c = 0;
    for (long long i = 0; i < s.length(); i++) {
      if ((isv(s[i]) && isv(ss[i])) || (!isv(s[i]) && !isv(ss[i]))) c++;
    }
    if (c == s.length())
      cout << "Yes\n";
    else
      cout << "No\n";
  } else
    cout << "No\n";
  return 0;
}
