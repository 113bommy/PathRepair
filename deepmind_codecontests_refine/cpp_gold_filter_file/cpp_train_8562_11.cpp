#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[110];
  cin >> str;
  int j = 1, res = 0;
  for (int i = 0; i < strlen(str); i++, j++) {
    if (str[i] == str[i + 1])
      continue;
    else {
      res += (j + 4) / 5;
      j = 0;
    }
  }
  cout << res << endl;
  return 0;
}
