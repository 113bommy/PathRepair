#include <bits/stdc++.h>
using namespace std;
int n, x, y, d, O4[100005], O7[100005], S4[100005], S7[100005];
char s[100005];
int tooLarge() {
  for (int i = 0; i < n / 2; i++) {
    if (s[i] > '7') return -1;
    if (s[i] < '7') return i;
  }
  for (int i = n / 2; i < n; i++) {
    if (s[i] > '4') return -1;
    if (s[i] < '4') return i;
  }
  return n;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  if (n % 2 == 0) {
    d = tooLarge();
    if (d < 0) n++;
  }
  if (n & 1) {
    n++;
    for (int i = 0; i * 2 < n; i++) printf("4");
    for (int i = 0; i * 2 < n; i++) printf("7");
    printf("\n");
    return 0;
  }
  S7[0] = (s[0] == '7');
  for (int i = 1; i < n; i++) S7[i] = S7[i - 1] + (s[i] == '7');
  S4[0] = (s[0] == '4');
  for (int i = 1; i < n; i++) S4[i] = S4[i - 1] + (s[i] == '4');
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] > '7')
      O7[i] = 0;
    else if (s[i] < '7')
      O7[i] = 1;
    else
      O7[i] = O7[i + 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] > '4')
      O4[i] = 0;
    else if (s[i] < '4')
      O4[i] = 1;
    else
      O4[i] = O4[i + 1];
  }
  x = y = n / 2;
  int ok = 0;
  for (int i = 0; i < n; i++) {
    if (ok) {
      if (y)
        printf("4"), y--;
      else
        printf("7"), x--;
    } else if (!x)
      printf("4"), y--;
    else if (!y)
      printf("7"), x--;
    else {
      if (s[i] == '7')
        printf("7"), x--;
      else if (s[i] < '4')
        printf("4"), y--, ok = 1;
      else if (s[i] == '4') {
        int c = 7;
        if (S7[i + x] - S7[i] == x) {
          if (S4[n - 1] - S4[i + x] == y - 1)
            c = 4;
          else if (O4[i + x + 1])
            c = 4;
        } else if (O7[i + 1])
          c = 4;
        if (c == 7)
          printf("7"), x--;
        else
          printf("4"), y--;
      } else
        printf("7"), x--, ok = 1;
    }
  }
  printf("\n");
  return 0;
}
