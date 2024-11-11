#include <bits/stdc++.h>
using namespace std;
char s[100100];
char x[110];
char y[110];
char temp[110];
int l1, l2, l3;
bool check() {
  bool c1 = false;
  bool c2 = false;
  int k = 0;
  int i, j;
  for (i = 0; i < l1 - l2 + 1; i++) {
    k = 0;
    j = i;
    while (k < l2 && s[j] == x[k]) {
      j++;
      k++;
    }
    if (k == l2) {
      c1 = true;
      break;
    }
  }
  fprintf(stderr, "%d %d\n", i, c1);
  int m = i + l2;
  for (i = m; i < l1 - l3 + 1; i++) {
    k = 0;
    j = i;
    while (k < l3 && s[j] == y[k]) {
      j++;
      k++;
    }
    if (k == l3) {
      c2 = true;
      break;
    }
  }
  fprintf(stderr, "%d %d\n", i, c2);
  return c1 & c2;
}
int main() {
  scanf("%s", s);
  scanf("%s", x);
  scanf("%s", y);
  l1 = strlen(s);
  l2 = strlen(x);
  l3 = strlen(y);
  bool p1 = check();
  reverse(s, s + l1);
  bool p2 = check();
  if (p1 && p2)
    printf("both\n");
  else if (p1)
    printf("forward\n");
  else if (p2)
    printf("backward\n");
  else
    printf("fantasy\n");
}
