#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[1010];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    if (s[i][0] == 'O' && s[i][1] == 'O') {
      cout << 'YES' << endl;
      s[i][0] = '+';
      s[i][1] = '+';
      for (int j = 0; j < n; j++) cout << s[i] << endl;
      return 0;
    } else if (s[i][3] == 'O' && s[i][4] == 'O') {
      cout << 'YES' << endl;
      s[i][3] = '+';
      s[i][4] = '+';
      for (int j = 0; j < n; j++) cout << s[i] << endl;
      return 0;
    }
  cout << 'NO';
  return 0;
}
