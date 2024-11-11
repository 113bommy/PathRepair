#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, c, b;
  cin >> c >> b;
  ;
  string s[2 * (c + b)];
  for (int i = 0; i < 2 * (c + b); i++) {
    cin >> s[i];
  }
  for (int i = (2 * c) + 1; i < 2 * (c + b); i = i + 2) {
    for (int j = 1; j < 2 * c; j = j + 2)
      if (s[i] == s[j] + ';')
        cout << s[i - 1] << " " << s[i] << " " << '#' << s[j - 1] << endl;
  }
}
