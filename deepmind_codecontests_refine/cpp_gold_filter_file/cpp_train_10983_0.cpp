#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int l = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == tolower(s[i])) l++;
  }
  if (l >= n - l)
    transform(s.begin(), s.end(), s.begin(), ::tolower);
  else
    transform(s.begin(), s.end(), s.begin(), ::toupper);
  cout << s;
}
