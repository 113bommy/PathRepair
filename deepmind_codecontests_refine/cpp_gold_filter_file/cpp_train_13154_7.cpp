#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  bool count[26];
  for (int i = 0; i <= 25; i++) count[i] = false;
  int check = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    count[s[i] - 97] = true;
  }
  for (int i = 0; i <= 25; i++) {
    if (count[i] == true) check++;
  }
  if (check % 2 == 0)
    cout << "CHAT WITH HER!";
  else
    cout << "IGNORE HIM!";
  return 0;
}
