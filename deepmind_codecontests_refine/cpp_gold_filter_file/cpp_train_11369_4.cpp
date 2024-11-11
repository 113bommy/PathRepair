#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch[5];
  char s[1000];
  int list_space[1000];
  int space = 0;
  int count = 0;
  while (scanf("%*[^(/a-z)]%[/a-z]", ch) != EOF) {
    if (ch[0] == '/') {
      list_space[count] = -1;
      s[count++] = ch[1];
    } else {
      list_space[count] = +1;
      s[count++] = ch[0];
    }
  }
  for (int j = 0; j < count - 1; j++) {
    if (list_space[j] == -1) space--;
    for (int k = 0; k < space; k++) cout << "  ";
    if (list_space[j] == -1)
      printf("</%c>\n", s[j]);
    else {
      printf("<%c>\n", s[j]);
      space++;
    }
  }
  return 0;
}
