#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, ocu = 0;
  char maxx = 'a';
  char str[11];
  char poo;
  scanf("%s", str);
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] > maxx) maxx = str[i];
  }
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == maxx) ocu++;
  }
  for (i = 1; i <= ocu; i++) printf("%c", maxx);
  return 0;
}
