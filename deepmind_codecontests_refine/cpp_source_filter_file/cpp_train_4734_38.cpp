#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int n;
  n = s.size() - 1;
  for (int i = n; i > 0; i--) {
    if (s[i] >= 'A' && s[i] <= 'z') {
      int c = s[i];
      if (isupper(c)) s[i] = tolower(c);
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u' || s[i] == 'y') {
        cout << "YES";
        return 0;
      } else {
        cout << "NO";
        return 0;
      }
    }
  }
}
