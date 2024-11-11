#include <bits/stdc++.h>
using namespace std;
char s[17 + 1];
char s1[17 + 1];
bool isopen(char s[], long i) {
  return (s[i] <= 'z' && s[i] >= 'a' && s[i - 1] != '/');
}
bool isclose(char s[], long i) {
  return (s[i] <= 'z' && s[i] >= 'a' && s[i - 1] == '/');
}
void printout(char c, long &curtab, char tabs[], long type) {
  if (type == 1) {
    cout << tabs << "<" << c << ">" << endl;
    tabs[curtab++] = ' ';
    tabs[curtab++] = ' ';
  } else if (type == 2) {
    curtab -= 2;
    tabs[curtab] = '\0';
    cout << tabs << "</" << c << ">" << endl;
  }
}
int main() {
  cin >> s;
  long len = strlen(s);
  long curtab = 0;
  s1[0] = '\0';
  for (long i = 0; i < len; i++) {
    if (isopen(s, i))
      printout(s[i], curtab, s1, 1);
    else if (isclose(s, i))
      printout(s[i], curtab, s1, 2);
  }
}
