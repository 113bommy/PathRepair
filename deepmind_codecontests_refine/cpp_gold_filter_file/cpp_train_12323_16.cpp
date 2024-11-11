#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k = 0;
  for (int i = 1; i <= 8; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if ((s[j] == 'W' && s[j + 1] == 'W') ||
          (s[j] == 'B' && s[j + 1] == 'B')) {
        k++;
        break;
      }
    }
  }
  if (k == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
