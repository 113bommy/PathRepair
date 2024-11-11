#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1;
  s1 = s1 + "0";
  cin >> s;
  int n, i, j, k, sum, y;
  n = s.length();
  y = count(s.begin(), s.end(), '0');
  if (y >= 1) {
    cout << "YES"
         << "\n";
    cout << "0";
    return 0;
  }
  s1 = s1 + s;
  s = s1;
  n = s.length();
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      for (k = j + 1; k < n; k++) {
        sum =
            0 + ((s[i] - '0') * 100) + ((s[j] - '0') * 10) + ((s[k] - '0') * 1);
        if ((sum % 8) == 0) {
          cout << "YES"
               << "\n";
          cout << sum;
          return 0;
        }
      }
    }
  }
  cout << "NO";
}
