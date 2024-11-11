#include <bits/stdc++.h>
using namespace std;
char s[100001];
int main() {
  gets(s);
  int l = strlen(s);
  bool flag = false;
  for (int i = 0; i < l; i++) {
    if (flag == true) {
      printf("<");
      while (s[i] != '"') {
        printf("%c", s[i]);
        i++;
      }
      flag = false;
      printf(">\n");
    } else if (s[i] == '"' && flag == false)
      flag = true;
    else if (s[i] == ' ') {
      continue;
    } else {
      printf("<");
      while (s[i] != ' ' && i < l) {
        printf("%c", s[i]);
        i++;
      }
      i--;
      printf(">\n");
    }
  }
  return 0;
}
