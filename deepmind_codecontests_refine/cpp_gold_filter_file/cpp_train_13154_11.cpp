#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  set<int> s1;
  for (int i = 0; s[i] != '\0'; i++) {
    s1.insert(s[i]);
  }
  if (s1.size() % 2 == 0) {
    cout << "CHAT WITH HER!";
  } else {
    cout << "IGNORE HIM!";
  }
}
