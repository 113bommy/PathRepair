#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[100010];
  scanf("%s", s);
  bool b = true;
  long len = strlen(s);
  for (long i = 0; i < len; i++) {
    if (b && s[i] == '0') {
      b = false;
      continue;
    }
    if (i != len - 1) putchar(s[i]);
  }
  printf("\n");
  return 0;
}
