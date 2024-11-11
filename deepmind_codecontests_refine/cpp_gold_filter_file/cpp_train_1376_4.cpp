#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> s;
    if (s[s.size() - 1] == 'o')
      cout << "FILIPINO"
           << "\n";
    else if (s[s.size() - 1] == 'u')
      cout << "JAPANESE"
           << "\n";
    else
      cout << "KOREAN"
           << "\n";
  }
  return 0;
}
