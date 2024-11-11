#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int o = 0, z = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      o++;
    else if (s[i] == ')')
      z++;
  }
  int pola = n / 2;
  if (n % 2 == 1 || z > pola || o > pola) {
    cout << ": (" << endl;
    return 0;
  }
  for (int i = 0; i < n && o < n / 2; i++) {
    if (s[i] == '?') {
      s[i] = '(';
      o++;
    }
  }
  int balans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') s[i] = ')';
    if (s[i] == '(')
      balans++;
    else
      balans--;
    if (balans <= 0 && i < n - 1) {
      cout << ": (" << endl;
      return 0;
    }
  }
  cout << s << endl;
  return 0;
}
