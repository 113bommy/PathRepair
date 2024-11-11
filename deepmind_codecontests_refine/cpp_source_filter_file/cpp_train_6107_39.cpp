#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, count = 0;
  string s;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == s[i + 1]) {
      count++;
      if (count == 7) break;
    } else
      count = 0;
  }
  if (count == 7)
    cout << "YES";
  else
    cout << "NO";
}
