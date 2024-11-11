#include <bits/stdc++.h>
int main() {
  char ch;
  int l[100000] = {0}, u[100000] = {0}, ans_0 = 0, ans_1 = 0, min = 100000,
      i = 0, j;
  while (1) {
    scanf("%c", &ch);
    if (ch == '\n') break;
    if (ch >= 'A' && ch <= 'Z')
      ans_1++;
    else
      ans_0++;
    l[i] = ans_0;
    u[i] = ans_1;
    i++;
  }
  if (l[i - 1] < min) min = l[i - 1];
  if (u[i - 1] < min) min = u[i - 1];
  for (j = 0; j < i - 1; j++)
    if (u[i - 1] - u[j] + l[j] < min) min = l[i - 1] - l[j] + u[j];
  printf("%d\n", min);
}
