#include <bits/stdc++.h>
char mi[128];
char str[100009];
bool check(char* begin, char* end) {
  while (begin <= end) {
    if (!mi[*begin] || mi[*begin] != mi[*end]) return false;
    begin++;
    end--;
  }
  return true;
}
int main() {
  for (int i = 0; i < 128; i++) mi[i] = 0;
  mi['A'] = 'A';
  mi['H'] = 'H';
  mi['I'] = 'I';
  mi['M'] = 'M';
  mi['O'] = 'O';
  mi['T'] = 'T';
  mi['U'] = 'U';
  mi['V'] = 'V';
  mi['W'] = 'W';
  mi['X'] = 'X';
  mi['Y'] = 'Y';
  scanf("%s", str);
  if (check(str, str + strlen(str) - 1)) {
    printf("YES");
  } else {
    printf("NO");
  }
}
