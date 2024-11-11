#include <bits/stdc++.h>
using namespace std;
char s[100010];
int mk[100010][26];
int main() {
  scanf("%s", s);
  for (int i = 0; i < 100010; i++) {
    for (int j = 0; j < 26; j++) {
      mk[i][j] = 0;
    }
  }
  for (int i = strlen(s) - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      mk[i][j] = mk[i + 1][j];
    }
    mk[i][(unsigned char)(s[i] - 'a')]++;
  }
  for (int i = 0; s[i]; i++) {
    char key = '0';
    for (int j = 25; j >= 0; j--) {
      if (mk[i][j]) {
        key = j + 'a';
        break;
      }
    }
    assert(key != '0');
    if (key == '0') {
      printf("%d\n", i);
    }
    while (s[i++] != key)
      ;
    i--;
    printf("%c", key);
  }
  printf("\n");
}
