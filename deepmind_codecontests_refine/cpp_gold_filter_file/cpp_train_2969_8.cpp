#include <bits/stdc++.h>
using namespace std;
int main() {
  int d;
  char of[3], str[10];
  scanf(" %d %s %s", &d, of, str);
  if (strcmp(str, "week") == 0) {
    if (d == 5 || d == 6)
      printf("53\n");
    else
      printf("52\n");
  } else {
    if (d >= 0 && d <= 29) printf("12\n");
    if (d == 30)
      printf("11\n");
    else if (d == 31)
      printf("7\n");
  }
  return 0;
}
