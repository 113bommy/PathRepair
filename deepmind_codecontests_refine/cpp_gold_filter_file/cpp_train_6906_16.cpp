#include <bits/stdc++.h>
using namespace std;
int fir = 0;
char s[1100000];
int check() {
  for (int i = 0; s[i]; i++) {
    if (s[i] == ' ') continue;
    if (s[i] == '#')
      return 1;
    else
      return 0;
  }
  return 0;
}
int main() {
  while (gets(s)) {
    if (check()) {
      if (fir) putchar('\n');
      puts(s);
      fir = 0;
    } else {
      for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') continue;
        putchar(s[i]);
      }
      fir = 1;
    }
  }
  if (fir) putchar('\n');
  return 0;
}
