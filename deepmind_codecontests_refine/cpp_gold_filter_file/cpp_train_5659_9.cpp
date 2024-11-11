#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[200];
  cin >> str;
  int i, l;
  l = strlen(str);
  for (i = 0; i < l; i++) {
    if ((str[i] == 'W') && (str[i + 1] == 'U') && (str[i + 2] == 'B')) {
      i = i + 2;
      cout << " ";
    } else
      cout << str[i];
  }
  return 0;
}
