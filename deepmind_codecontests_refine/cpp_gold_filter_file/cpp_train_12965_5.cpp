#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, a[19] = {2,  3,  4,  5,  7,  9,  25, 49, 11, 13,
                  17, 19, 23, 29, 31, 37, 41, 43, 47},
         t = 0;
  for (i = 0; i < 19; i++) {
    printf("%d\n", a[i]);
    fflush(stdout);
    char s[4];
    scanf("%s", s);
    if (strcmp(s, "yes") == 0) t++;
  }
  printf("%s\n", (t > 1) ? "composite" : "prime");
  fflush(stdout);
}
