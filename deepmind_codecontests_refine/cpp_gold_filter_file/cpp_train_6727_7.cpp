#include <bits/stdc++.h>
using namespace std;
char s[3005];
int n, m, x, y, z, k, w;
int find(char s) {
  if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return 1;
  return 0;
}
int check(int f, int t) {
  int tmp = 0, diff = 0;
  for (int i = (f); i <= (t); i++) {
    if (find(s[i]) == 1) {
      tmp = 0;
      diff = 0;
    } else {
      tmp++;
      if (i > f && find(s[i - 1]) == 0 && s[i] != s[i - 1]) diff = 1;
    }
    if (diff == 1 && tmp >= 3) return 0;
  }
  return 1;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  x = 0;
  for (int i = (0); i < (n); i++) {
    if (check(x, i) == 0) {
      printf(" %c", s[i]);
      x = i;
    } else
      printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}
