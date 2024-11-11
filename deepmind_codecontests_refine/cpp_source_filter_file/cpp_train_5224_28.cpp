#include <bits/stdc++.h>
using namespace std;
int s[10];
int main() {
  memset(s, 0, sizeof(s));
  char ch;
  int n;
  scanf("%d", &n);
  getchar();
  while (n--) {
    scanf("%c", &ch);
    if (ch == 'L') {
      for (int i = 0; i < 9; i++) {
        if (s[i] == 0) {
          s[i] = 1;
          break;
        }
      }
    } else if (ch == 'R') {
      for (int i = 9; i >= 0; i--) {
        if (s[i] == 0) {
          s[i] = 1;
          break;
        }
      }
    } else {
      int l = ch - '0';
      s[l] = 0;
    }
  }
  for (int i = 0; i <= 9; i++) printf("%d", s[i]);
  printf("\n");
  return 0;
}
