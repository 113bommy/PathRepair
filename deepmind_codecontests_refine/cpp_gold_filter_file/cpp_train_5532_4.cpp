#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0, d = 0;
  string s;
  cin >> s;
  int p = s.size();
  for (int i = 0; i < p; i++) {
    if (s[i] != '4' || s[i] != '7') c++;
  }
  for (int i = 0; i < p; i++) {
    if (s[i] == '4' || s[i] == '7') d++;
  }
  if (c == 0 || d == 4 || d == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
