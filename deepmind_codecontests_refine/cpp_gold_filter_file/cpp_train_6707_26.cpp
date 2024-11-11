#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, i = 0, t = 0, e = 0;
  string s;
  cin >> s;
  for (int j = 0; j < s.size(); j++) {
    if (s[j] == 'n') n++;
    if (s[j] == 'i') i++;
    if (s[j] == 't') t++;
    if (s[j] == 'e') e++;
  }
  cout << min((n - 1) / 2, min(i, min(t, e / 3)));
}
