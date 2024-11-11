#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n, flag = 0;
  cin >> n;
  char s[n][6];
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++) {
    if (s[i][0] == 'O' && s[i][1] == 'O') {
      s[i][0] = '+';
      s[i][1] = '+';
      flag = 1;
    } else if (flag == 0 && s[i][3] == 'O' && s[i][4] == 'O') {
      s[i][3] = '+';
      s[i][4] = '+';
      flag = 1;
    } else if (flag == 1)
      break;
    else
      continue;
  }
  if (flag == 0)
    cout << "NO";
  else {
    cout << "YES" << endl;
    for (i = 0; i < n; i++) cout << s[i] << endl;
  }
}
