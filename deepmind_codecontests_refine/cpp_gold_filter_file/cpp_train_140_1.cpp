#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int main() {
  cin >> s >> k;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] - 'a' >= 0 && s[i] - 'a' < k) s[i] = toupper(s[i]);
    if (s[i] - 'A' >= k && s[i] - 'A' < 26) s[i] = tolower(s[i]);
  }
  cout << s << endl;
  return 0;
}
