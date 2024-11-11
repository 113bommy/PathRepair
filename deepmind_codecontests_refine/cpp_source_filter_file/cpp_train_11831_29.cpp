#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int counter = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == '0' || s[i] == '2' || s[i] == '4' ||
        s[i] == '6' || s[i] == '8') {
      counter++;
    }
  }
  cout << counter;
}
