#include <bits/stdc++.h>
using namespace std;
char s[1005];
int len2(char *s) {
  int x, y;
  sscanf(s, "%*[^>]>%n%*[^\0]%n", &x, &y);
  return y - x;
}
int len3(char *s) {
  char str[256];
  sscanf(s, "%[^=]", str);
  printf(str);
  cout << endl;
}
int len4(char *s) {
  char str[256];
  sscanf(s, "%*[^=]=%s", str);
  printf(str);
  cout << endl;
}
int len(char *s) {
  int len = strlen(s);
  int ptr = 0;
  while ((s[ptr] != ':') && (ptr < len)) ptr++;
  return len - ptr - 1;
}
int main() {
  int res = 0;
  int p = 0;
  while (gets(s)) {
    if (s[0] == '+')
      p++;
    else if (s[0] == '-')
      p--;
    else
      res += p * len(s);
  }
  cout << res << endl;
}
