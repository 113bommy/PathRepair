#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    long long ans = 0;
    while (1) {
      int f = 0;
      if (s.length() >= 2) {
        for (int i = 0; i < s.length() - 1 and s.length() >= 2; i++) {
          if ((s[i] == '0' && s[i + 1] == '1') ||
              (s[i] == '1' && s[i + 1] == '0')) {
            s.erase(i, 2);
            ans++;
            f = 1;
          }
        }
      }
      if (f == 0) {
        break;
      }
    }
    if (ans % 2 != 0)
      cout << "DA"
           << "\n";
    else
      cout << "NET"
           << "\n";
  }
  return 0;
}
