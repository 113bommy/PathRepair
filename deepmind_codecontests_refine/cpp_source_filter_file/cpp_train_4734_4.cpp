#include <bits/stdc++.h>
using namespace std;
char cad[1000];
bool isvocal(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    return true;
  return false;
}
bool iscon(char c) {
  c = tolower(c);
  for (char i = 'a'; i < 'z'; i++) {
    if (c == i) {
      return true;
    }
  }
  return false;
}
int main() {
  scanf(" %[^\n]", cad);
  int len = strlen(cad);
  for (int i = len - 1; i >= 0; i--) {
    if (isvocal(cad[i])) {
      printf("YES\n");
      return 0;
    } else if (iscon(cad[i])) {
      printf("NO\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
