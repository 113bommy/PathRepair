#include <bits/stdc++.h>
using namespace std;
char f(char a, char b) {
  if (a == b && a == 'R')
    return 'B';
  else if (a == b)
    return 'R';
  int sum = 'R' + 'G' + 'B';
  return (char)(sum - (int)(a) - (int)(b));
}
int main() {
  int n, c = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i < n - 1; i++) {
    if (s[i - 1] == s[i]) {
      s[i] = f(s[i - 1], s[i + 1]);
      c++;
    }
  }
  if (s[n - 2] == s[n - 1]) {
    s[n - 1] = f(s[n - 2], s[n - 3]);
    c++;
  }
  cout << c << endl << s;
  return 0;
}
