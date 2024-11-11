#include <bits/stdc++.h>
using namespace std;
char str[1005][1005];
int main(int argc, char const* argv[]) {
  int s1 = 0, s2 = 0;
  for (int i = 0; gets(str[i]); i++) {
    for (int j = 0; str[i][j]; j++) {
      if (!isalpha(str[i][j])) continue;
      bool up = isupper(str[i][j]);
      char ch = tolower(str[i][j]);
      int k = 0;
      if (ch == 'q') k = 9;
      if (ch == 'r') k = 5;
      if (ch == 'b') k = 3;
      if (ch == 'k') k = 3;
      if (ch == 'p') k = 1;
      if (up)
        s1 += k;
      else
        s2 += k;
    }
  }
  if (s1 == s2)
    printf("Draw\n");
  else if (s1 > s2)
    printf("White\n");
  else
    printf("Black\n");
  return 0;
}
