#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0;
  string s;
  cin >> n >> s;
  while (s[i] != '\0') {
    if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
      cout << "***";
      i += 3;
      while (s[i] == 'g' && s[i + 1] == 'o') i += 2;
    } else {
      cout << s[i];
      i++;
    }
  }
}
