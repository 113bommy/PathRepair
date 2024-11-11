#include <bits/stdc++.h>
using namespace std;
string s;
string s1;
int main() {
  cin >> s;
  cin >> s1;
  int j = 0;
  bool a = true;
  int g1 = -1, g2;
  int i;
  for (i = 0; i < s1.size(); i++) {
    if (s[j] != s1[i]) {
      if (!a) {
        cout << 0;
        return 0;
      }
      g1 = i;
      g2 = g1;
      a = false;
      i--;
    }
    j++;
  }
  if (g1 == -1) {
    g1 = s1.size();
    g2 = g1;
  }
  for (i = g1 - 1; i >= 0; i--) {
    if (s[i] == s[g1]) {
      g2--;
    } else
      break;
  }
  cout << g1 - g2 + 1 << '\n';
  for (i = g2; i <= g1; i++) cout << i + 1 << ' ';
  return 0;
}
