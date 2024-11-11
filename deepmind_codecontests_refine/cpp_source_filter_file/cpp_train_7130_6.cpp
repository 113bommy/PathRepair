#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, c;
  char S[105];
  char str[20][101] = {"ABSINTH", "BEER",    "BRANDY", "CHAMPAGNE",
                       "GIN",     "RUM",     "SAKE",   "TEQUILA",
                       "VODKA",   "WHISKEY", "WINE"};
  while (scanf("%d", &n) == 1) {
    k = 0;
    for (i = 0; i < n; i++) {
      scanf("%s", S);
      c = 0;
      if (isdigit(S[0])) {
        if (atoi(S) <= 17) k++;
      } else {
        for (j = 0; j < 11; j++)
          if (!strcmp(S, str[j])) {
            c = 1;
            break;
          }
        if (!c) k++;
      }
    }
    printf("%d\n", k);
  }
  return 0;
}
