#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  string s = "";
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s[s.length() - 1] == 'o')
      cout << "FILIPINO\n";
    else {
      if (s[s.length() - 1] == 'a')
        cout << "KOREAN\n";
      else
        cout << "JAPANESE\n";
    }
  }
  return 0;
}
