#include <bits/stdc++.h>
using namespace std;
int main(void) {
  string s;
  cin >> s;
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  string l = "abcdefghijklmnopqrstuvwxyz";
  string L = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  map<char, char> m;
  for (int i = 0; i < l.size(); i++) m[l[i]] = L[i];
  int n;
  cin >> n;
  n = n + 'a' - 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] < n) s[i] = m[s[i]];
  }
  cout << s << endl;
}
