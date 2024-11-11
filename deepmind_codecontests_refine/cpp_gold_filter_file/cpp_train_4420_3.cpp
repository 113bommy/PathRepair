#include <bits/stdc++.h>
using namespace std;
bool let[26];
int main() {
  string s;
  int i, med, x, cont = 0;
  getline(cin, s);
  med = s.size();
  for (i = 0; i < med; i++) {
    x = s[i] - 'a';
    if (x >= 0 && x < 26) let[x] = true;
  }
  for (i = 0; i < 26; i++) {
    if (let[i]) cont++;
  }
  cout << cont << "\n";
  return 0;
}
