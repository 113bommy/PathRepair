#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
int main() {
  int n;
  int sum;
  int nChet, nNechet;
  int buff;
  scanf("%i", &n);
  if (n == 1)
    printf("1");
  else {
    sum = 0;
    nChet = 0;
    nNechet = 0;
    for (; n > 0; n--) {
      scanf("%i", &buff);
      if (buff % 2 == 0)
        nChet++;
      else
        nNechet++;
      sum += buff;
    }
    if (sum % 2 == 0)
      printf("%i", nChet);
    else
      printf("%i", nNechet);
  }
  return 0;
}
