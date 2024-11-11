#include <bits/stdc++.h>
using namespace std;
bool is_vowel(char a) {
  return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}
int main() {
  string str[3];
  for (int i = 0; i < 3; i++) getline(cin, str[i]);
  bool c[3] = {false};
  int count = 0;
  for (int i = 0; i < str[0].size(); i++) {
    if (is_vowel(str[0][i])) count++;
  }
  if (count == 5) c[0] = true;
  count = 0;
  for (int i = 0; i < str[1].size(); i++) {
    if (is_vowel(str[1][i])) count++;
  }
  if (count == 7) c[1] = true;
  count = 0;
  for (int i = 0; i < str[2].size(); i++) {
    if (is_vowel(str[2][i])) count++;
  }
  if (count == 5) c[2] = true;
  string ans = "NO";
  if (c[0] && c[1] && c[2]) ans = "YES";
  cout << ans << endl;
  return 0;
}
