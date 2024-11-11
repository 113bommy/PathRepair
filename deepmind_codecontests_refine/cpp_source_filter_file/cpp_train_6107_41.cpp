#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  long long x = 0;
  bool bb = 0;
  string s;
  cin >> s;
  if (s.length() < 8)
    cout << "NO";
  else {
    for (int i = 0; i < s.length(); i++) {
      for (int j = i + 1; j < i + 7; j++) {
        if (s[j] == s[i] && j == i + 6)
          bb = 1;
        else if (s[i] != s[j]) {
          break;
        }
      }
      if (bb == 1) break;
    }
    if (bb == 1)
      cout << "YES";
    else
      cout << "N0";
  }
}
