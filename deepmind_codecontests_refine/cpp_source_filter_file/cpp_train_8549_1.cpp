#include <bits/stdc++.h>
using namespace std;
char s[100010];
int main() {
  scanf("%s", s);
  int sum = 0;
  int len = strlen(s);
  int a, b;
  int len2 = len;
  int flag = 0;
  int c;
  for (b = 0; b <= len / 2; b++) {
    flag = 0;
    for (a = 0; a <= len2 - 1; a++) {
      if (s[a] == s[a + 1]) {
        for (c = a; c <= len2 - 3; c++) {
          s[c] = s[c + 2];
        }
        sum++;
        len2 -= 2;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      break;
    }
  }
  if (sum % 2 == 0)
    printf("No\n");
  else
    printf("Yes\n");
  return 0;
}
