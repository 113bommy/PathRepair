#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[101];
  cin >> str;
  int i, l;
  l = strlen(str);
  for (i = 0; i < l; i++) {
    if ((str[i] == 'w') && (str[i + 1] == 'u') && (str[i + 2] == 'b')) {
      i = i + 2;
      cout << " ";
    } else
      cout << str[i];
  }
  return 0;
}
