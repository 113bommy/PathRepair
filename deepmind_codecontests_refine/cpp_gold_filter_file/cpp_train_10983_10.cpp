#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k = 0, j = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (isupper(s[i])) k++;
    if (islower(s[i])) j++;
  }
  for (int i = 0; i < s.size(); i++) {
    if (j >= k) {
      if (isupper(s[i])) s[i] = tolower(s[i]);
    } else if (islower(s[i]))
      s[i] = toupper(s[i]);
  }
  cout << s;
  return 0;
}
