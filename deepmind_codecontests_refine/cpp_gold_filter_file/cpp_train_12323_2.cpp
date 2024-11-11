#include <bits/stdc++.h>
using namespace std;
int main() {
  bool f = false;
  string s;
  for (int i = 0; i < 8; i++) {
    cin >> s;
    for (int j = 0; j < 7; j++) {
      if (s[j] == s[j + 1]) f = true;
    }
  }
  if (f)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
