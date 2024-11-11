#include <bits/stdc++.h>
char s1[2000], s2[2000];
char getch(FILE *fin) {
  char ch = fgetc(fin);
  while (!isalpha(ch)) ch = fgetc(fin);
  return ch;
}
char aux[2000];
int top;
int move[8000];
void smec(int x, int n) {
  if (x > 0) move[top++] = x;
  for (int i = 0; i < x; ++i) aux[i] = s1[n - i - 1];
  for (int i = n - x - 1; i >= 0; --i) s1[i + x] = s1[i];
  for (int i = 0; i < x; ++i) s1[i] = aux[i];
}
int main() {
  int n, lastdif;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) s1[i] = getch(stdin);
  for (int i = 0; i < n; ++i) s2[i] = getch(stdin);
  for (int i = n - 1; i >= 0; --i) {
    int j = 0;
    while (j <= i && j < n && s1[j] != s2[i]) ++j;
    if (j > i) {
      printf("-1");
      return 0;
    }
    smec(n - j - 1, n);
    smec(1, n);
    smec(n, n);
  }
  printf("%d\n", top);
  for (int i = 0; i < top; ++i) printf("%d ", move[i]);
  return 0;
}
