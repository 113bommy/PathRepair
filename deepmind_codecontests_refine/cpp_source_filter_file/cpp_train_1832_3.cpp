#include <bits/stdc++.h>
using namespace std;
int main() {
  int p = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - i - 1]) {
      p++;
      if (p > 0) break;
    }
  }
  if (p == 1)
    cout << "YES";
  else if (p == 0 && s.length() % 2 == 1)
    cout << "YES";
  else
    cout << "NO";
}
