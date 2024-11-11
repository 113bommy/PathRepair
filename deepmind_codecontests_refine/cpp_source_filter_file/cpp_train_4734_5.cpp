#include <bits/stdc++.h>
using namespace std;
string s = "";
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  char c[100];
  cin.getline(c, 100);
  s = c;
  for (int i = s.length() - 1; i >= 0; --i) {
    if (s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A') {
      if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' ||
          tolower(s[i]) == 'i' || tolower(s[i]) == 'o' ||
          tolower(s[i]) == 'u' || tolower(s[i]) == 'y')
        cout << "YES\n";
      else
        cout << "no\n";
      return 0;
    }
  }
}
