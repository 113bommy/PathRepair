#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s.length() < 5) {
    cout << "Too weak";
    return 0;
  } else {
    int upper = 0, lower = 0, digits = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 65 && s[i] <= 90)
        upper++;
      else if (s[i] >= 97 && s[i] <= 122)
        lower++;
      if (s[i] >= 48 && s[i] <= 56) digits++;
    }
    if (upper && lower && digits)
      cout << "Correct";
    else
      cout << "Too weak";
  }
  return 0;
}
