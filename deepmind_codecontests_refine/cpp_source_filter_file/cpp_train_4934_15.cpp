#include <bits/stdc++.h>
bool valid(int n[]) {
  int d = n[0], m = n[1], y = n[2];
  int mle[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (y % 4 == 0) mle[1]++;
  return (m <= 12 && d <= mle[m]);
}
void readDate(int d[]) {
  char s[10];
  scanf("%s", s);
  d[0] = (s[0] - 48) * 10 + (s[1] - 48);
  d[1] = (s[3] - 48) * 10 + (s[4] - 48);
  d[2] = (s[6] - 48) * 10 + (s[7] - 48);
}
bool old(int f[], int n[]) {
  int off = 0;
  if (f[1] < n[1] || (f[1] == n[1] && f[0] < n[0])) off = 1;
  return f[2] - n[2] - off >= 18;
}
int main(int agrc, char *argv[]) {
  int f[3];
  readDate(f);
  int b[3];
  readDate(b);
  for (int i = 0; i < 6; i++) {
    int n[3] = {b[i / 2], b[(1 + (i + 1) / 2) % 3], b[2 - (i % 3)]};
    if (valid(n) && old(f, n)) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
