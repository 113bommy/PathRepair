#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, count = 0;
  cin >> t;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    s[i] = tolower(c);
  }
  if (t < 26)
    cout << "NO";
  else {
    int i = 0;
    for (int j = 0; j < s.length(); j++) {
      if ((int)s[j] == i + 97) {
        count++;
        i++;
        j = 0;
      }
    }
    if (count == 26)
      cout << "YES";
    else
      cout << "NO";
  }
}
