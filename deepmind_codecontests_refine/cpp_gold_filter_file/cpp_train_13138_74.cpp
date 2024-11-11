#include <bits/stdc++.h>
using namespace std;
int len;
char ch;
char T[1000010];
int nexxt[1000010];
int find_t(int le) {
  int i = 1, j = 0;
  while (i < len - 1 && j <= le) {
    if (j == -1 || T[i] == T[j]) {
      i++;
      j++;
    } else
      j = nexxt[j];
  }
  if (j == le + 1) return 1;
  return 0;
}
int bo(int le) {
  int y = len;
  while (nexxt[y] >= le + 1) {
    if (nexxt[y] == le + 1)
      return 1;
    else
      y = nexxt[y];
  }
  return 0;
}
int main() {
  int i, j;
  len = 0;
  while ((ch = getchar()) != '\n') {
    T[len] = ch;
    len++;
  }
  T[len] = '4';
  nexxt[0] = -1;
  nexxt[1] = 0;
  for (i = 2; i <= len; i++) {
    j = i - 1;
    while (nexxt[j] != -1 && T[nexxt[j]] != T[i - 1]) {
      j = nexxt[j];
    }
    nexxt[i] = nexxt[j] + 1;
  }
  for (i = len - 2; i >= 0; i--) {
    if (i == -1) break;
    if (bo(i) && find_t(i)) break;
  }
  if (i == -1)
    printf("Just a legend");
  else {
    for (j = 0; j <= i; j++) {
      printf("%c", T[j]);
    }
  }
  return 0;
}
