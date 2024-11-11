#include <bits/stdc++.h>
using namespace std;
int main() {
  int sz;
  string s;
  cin >> sz >> s;
  string t;
  for (int i = 0; i < sz; i++) {
    char c = s[i];
    if (c == 'a' or c == 'i' or c == 'u' or c == 'y') {
      if (i == sz - 1 or c != s[i + 1]) t += c;
    } else if (c == 'e' or c == 'o') {
      int count = 0;
      while (s[++i] == c) count++;
      t += c;
      if (count == 1) t += c;
      i--;
    } else {
      t += c;
    }
  }
  cout << t << endl;
  return 0;
}
