#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[210];
  int check[210];
  int temp = 0;
  scanf("%s", s);
  int l = strlen(s);
  for (int i = 0; i < l; i++) {
    if (s[i] == '@') {
      check[temp] = i;
      temp++;
    }
  }
  if (temp == 0) {
    printf("NO solution");
    return 0;
  }
  for (int i = 0; i < temp - 1; i++) {
    if (check[i + 1] - check[i] <= 2) {
      printf("No solution");
      return 0;
    }
  }
  if (s[0] == '@' || s[l - 1] == '@') {
    printf("No solution");
    return 0;
  }
  for (int i = 0; i < l; i++) {
    if (s[i] == '@') {
      printf("@");
      printf("%c", s[i + 1]);
      if (i != check[temp - 1]) {
        printf(",");
      }
      i++;
    } else {
      printf("%c", s[i]);
    }
  }
}
