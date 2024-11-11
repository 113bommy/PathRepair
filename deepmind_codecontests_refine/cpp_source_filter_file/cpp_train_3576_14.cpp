#include <bits/stdc++.h>
int cards[52][52][52][52];
int hash[100];
void recurse(char **s, int i1, int i2, int i3, int n);
int flag = 0;
int iscomplete(int i1, int i2, int i3);
int main() {
  int i, j, n;
  for (i = 50; i <= 57; i++) hash[i] = i - 50;
  hash[84] = 8;
  hash[74] = 9;
  hash[81] = 10;
  hash[75] = 11;
  hash[65] = 12;
  hash[83] = 0;
  hash[68] = 1;
  hash[72] = 2;
  hash[67] = 3;
  scanf("%d", &n);
  char **s = (char **)malloc(sizeof(char *) * n);
  for (i = 0; i < n; i++) s[i] = (char *)calloc(3, sizeof(char));
  for (i = 0; i < n; i++) scanf("%s", s[i]);
  if (n == 1) {
    printf("YES\n");
    return (0);
  }
  if (n == 2) {
    i = hash[(int)s[0][0]] + 13 * hash[(int)s[0][1]];
    j = hash[(int)s[1][0]] + 13 * hash[(int)s[1][1]];
    if ((i % 13 == j % 13) || (i / 13 == j / 13)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
    return (0);
  }
  int i1, i2, i3;
  i1 = hash[(int)s[n - 3][0]] + 13 * hash[(int)s[n - 3][1]];
  i2 = hash[(int)s[n - 2][0]] + 13 * hash[(int)s[n - 2][1]];
  i3 = hash[(int)s[n - 1][0]] + 13 * hash[(int)s[n - 1][1]];
  flag = 0;
  recurse(s, i1, i2, i3, n);
  if (flag == 1)
    printf("YES\n");
  else
    printf("NO\n");
  return (0);
}
void recurse(char **s, int i1, int i2, int i3, int n) {
  int i, j, i4;
  if (cards[i1][i2][i3][n - 1] == 1) return;
  cards[i1][i2][i3][n - 1] = 1;
  if (n == 3) {
    if (iscomplete(i1, i2, i3) == 1) flag = 1;
    return;
  }
  if (flag == 1) return;
  i4 = hash[(int)s[n - 4][0]] + 13 * hash[(int)s[n - 4][1]];
  if ((i2 % 13 == i3 % 13) || (i2 / 13 == i3 / 13)) {
    recurse(s, i4, i1, i3, n - 1);
  }
  if (flag == 1) return;
  if ((i4 % 13 == i3 % 13) || (i4 / 13 == i3 / 13)) {
    recurse(s, i3, i1, i2, n - 1);
  }
  if (flag == 1) return;
}
int iscomplete(int i1, int i2, int i3) {
  if ((i3 % 13 == i2 % 13) || (i3 / 13 == i2 / 13)) {
    if ((i3 % 13 == i1 % 13) || (i3 / 13 == i2 / 13)) return (1);
  }
  return (0);
}
