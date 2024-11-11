#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ptr = (int)'a';
  int su = 0;
  for (int i = 0; i < s.length(); i++) {
    su += min(26 - abs((int)ptr - (int)s[i]), abs((int)s[i] - (int)ptr));
    ptr = (int)s[i];
  }
  cout << su << endl;
}
