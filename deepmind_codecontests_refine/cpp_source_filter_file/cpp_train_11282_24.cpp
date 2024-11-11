#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int pos = 1;
  for (unsigned int i = 0, j = 0; j < s.length(); j++) {
    if (s[i] == t[j]) {
      i++;
      pos = i + 1;
    }
  }
  cout << pos << endl;
  return 0;
}
