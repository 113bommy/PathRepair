#include <bits/stdc++.h>
using namespace std;
struct bot {
  bool first;
  string second;
};
int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  for (int i = 0; i < s2.length(); i++) {
    int j = 0;
    if (s2[i] != ' ')
      for (j = 0; j < s1.length(); j++)
        if (s1[j] == s2[i]) {
          s1[j] = ' ';
          break;
        }
    if (j == s1.length()) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
