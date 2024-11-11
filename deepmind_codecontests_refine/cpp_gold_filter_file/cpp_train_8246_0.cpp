#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, c = 0, i;
  cin >> n;
  string s;
  cin >> s;
  for (char z = 'z'; z >= 'a'; z--) {
    n = s.length();
    for (long long j = 0; j < 2 * 100; j++) {
      n = s.length();
      for (i = 0; i < s.length(); i++) {
        if (s[i] == z) {
          if (i == 0 && s[i + 1] == (z - 1)) {
            c++;
            s.erase(s.begin() + i);
            break;
          } else if (i == (n - 1) && s[i - 1] == (z - 1)) {
            c++;
            s.erase(s.begin() + i);
            break;
          } else {
            if (s[i + 1] == z - 1 || s[i - 1] == z - 1) {
              c++;
              s.erase(s.begin() + i);
              break;
            }
          }
        }
      }
    }
  }
  cout << c << "\n";
  return 0;
}
