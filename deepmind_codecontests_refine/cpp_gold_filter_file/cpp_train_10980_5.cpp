#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cont = 0;
  int x[30] = {0};
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
  for (int i = 0; i < s.length(); i++) {
    if ((i % 2) == 0)
      x[s[i] - 97]++;
    else {
      if (x[s[i] - 97] > 0)
        x[s[i] - 97]--;
      else {
        cont++;
      }
    }
  }
  cout << cont << endl;
  return 0;
}
