#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, sum = 0, c = 0;
  string s;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (s[i] >= 65 && s[i] < 90) sum++;
  }
  if (sum == s.length()) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
    return 0;
  }
  for (i = 1; i < s.length(); i++) {
    if (s[i] >= 65 && s[i] < 90) c++;
  }
  if (c == s.length() - 1) {
    s[0] = toupper(s[0]);
    transform(s.begin() + 1, s.end(), s.begin() + 1, ::tolower);
    cout << s << endl;
    return 0;
  }
  cout << s << endl;
}
