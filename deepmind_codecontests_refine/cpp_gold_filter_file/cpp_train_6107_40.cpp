#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, count = 0;
  string s;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == s[i + 1]) {
      count++;
      if (count == 6) break;
    } else
      count = 0;
  }
  if (count == 6)
    cout << "YES";
  else
    cout << "NO";
}
