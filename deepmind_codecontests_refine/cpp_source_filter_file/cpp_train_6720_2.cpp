#include <bits/stdc++.h>
int main() {
  int Mishka, mishkaWin = 0;
  int Chris, chrisWin = 0;
  int numberOfPlay;
  int i;
  scanf("%d", &numberOfPlay);
  for (i = 1; i <= numberOfPlay; i++) {
    scanf("%d %d", &Mishka, &Chris);
    if (Mishka > Chris) {
      mishkaWin++;
    }
    if (Chris > Mishka) {
      chrisWin++;
    }
  }
  if (mishkaWin > chrisWin) {
    printf("Mishka");
  } else if (chrisWin > mishkaWin) {
    printf("Chris");
  } else {
    printf("Friendship is Magic!^^");
  }
  return 0;
}
