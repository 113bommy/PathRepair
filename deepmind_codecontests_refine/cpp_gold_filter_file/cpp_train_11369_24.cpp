#include <bits/stdc++.h>
using namespace std;
string s;
int i, j, sum;
int main() {
  cin >> s;
  for (i = 0; i < s.length(); (s[i + 1] == '/') ? i += 4 : i += 3) {
    for (j = 1; j <= sum; j++) cout << " ";
    for (j = 0; j < ((s[i + 1] == '/') ? 4 : 3); j++) cout << s[i + j];
    cout << endl;
    if (s[i + 1] != '/' && s[i + 4] != '/')
      sum += 2;
    else if (s[i + 1] == '/' && s[i + 5] == '/')
      sum -= 2;
  }
  return 0;
}
