#include <bits/stdc++.h>
using namespace std;
int main() {
  int counter = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == '0' || s[i] == '2' || s[i] == '4' ||
        s[i] == '6' || s[i] == '8')
      counter++;
  }
  cout << counter;
  return 0;
}
