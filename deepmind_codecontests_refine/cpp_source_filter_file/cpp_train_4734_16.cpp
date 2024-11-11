#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[101];
  cin.get(str, 101);
  char *cht = str;
  int position = 0;
  while (*cht != '?') {
    position++;
    cht++;
  }
  cht--;
  if (*cht == ' ') {
    cht--;
  }
  if (*cht == 'A' || *cht == 'E' || *cht == 'I' || *cht == 'O' || *cht == 'U' ||
      *cht == 'Y' || *cht == 'a' || *cht == 'e' || *cht == 'i' || *cht == 'o' ||
      *cht == 'u' || *cht == 'y') {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
