#include <bits/stdc++.h>
int main() {
  char s[100];
  fgets(s, sizeof(s) + 1, stdin);
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
}
