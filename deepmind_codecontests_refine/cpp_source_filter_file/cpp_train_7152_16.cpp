#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 1; i < s.length() - 1; i++) {
    if (s[i] == 'A' && (s[i - 1] == 'B' && s[i + 1] == 'C' ||
                        s[i - 1] == 'C' && s[i + 1] == 'B')) {
      cout << "Yes";
      return 0;
    }
    if (s[i] == 'B' && (s[i - 1] == 'A' && s[i + 1] == 'C' ||
                        s[i - 1] == 'C' && s[i + 1] == 'A')) {
      cout << "Yes";
      return 0;
    }
    if (s[i] == 'C' && (s[i - 1] == 'B' && s[i + 1] == 'A' ||
                        s[i - 1] == 'C' && s[i + 1] == 'A')) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
