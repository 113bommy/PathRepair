#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int N;
  scanf("%i", &N);
  int i;
  int dva[30];
  dva[0] = 1;
  for (i = 1; i < 20; i++) {
    dva[i] = 2 * dva[i - 1];
  }
  int stav = 0;
  for (i = 20; i >= 0; i--) {
    if ((N & dva[i]) != 0) {
      if (stav == 0)
        printf("%i", i + 1);
      else
        printf(" %i", i + 1);
      stav = 1;
    }
  }
  printf("\n");
  return 0;
}
