#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  if (n == 3)
    printf(">vv\n^<.\n^.<\n1 3\n");
  else if (n == 5)
    printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
  else {
    for (int k = 1; k <= 50; k++) {
      for (int i = 1; i <= 49; i++) printf(">");
      for (int i = 1; i <= 50; i++)
        if (i & 1)
          printf(".");
        else
          printf(">");
      printf("v\n");
      printf("^");
      for (int i = 1; i <= 50; i++)
        if (i & 1)
          printf("<");
        else
          printf(".");
      for (int i = 1; i <= 49; i++) printf("<");
      printf("\n");
    }
    printf("1 100\n");
  }
  return 0;
}
