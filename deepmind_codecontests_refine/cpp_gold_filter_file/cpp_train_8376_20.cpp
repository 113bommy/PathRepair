#include <bits/stdc++.h>
using namespace std;
char c[500];
int cn;
char d[500];
int N;
int B[500];
bool fill(char *p, int x, int cnt) {
  if (x > 9 * (cn - cnt)) return false;
  for (int i = 0; cnt + i < cn; i++) {
    int t = max(0, x - 9 * (cn - 1 - cnt - i));
    p[i] = t + '0';
    x -= t;
  }
  return true;
}
bool find(char *p, int x, int cnt) {
  if (cnt == cn) return false;
  if (x > c[cnt] - '0' && x <= 9 * (cn - cnt)) {
    *p = c[cnt];
    if (x - c[cnt] + '0' <= 9 * (cn - 1 - cnt) &&
        find(p + 1, x - c[cnt] + '0', cnt + 1))
      return true;
    else if (c[cnt] == '9')
      return false;
    else if (x - c[cnt] - 1 + '0' <= 9 * (cn - 1 - cnt)) {
      *p = c[cnt] + 1;
      fill(p + 1, x - c[cnt] - 1 + '0', cnt + 1);
      return true;
    } else {
      int t = x - 9 * (cn - 1 - cnt);
      *p = t + '0';
      fill(p + 1, x - t, cnt + 1);
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &N);
  for (int Ni = 0; Ni < N; Ni++) scanf("%d", &B[Ni]);
  if (B[0] % 9 == 0) {
    for (int i = 0; i < B[0] / 9; i++) c[i] = '9';
    c[B[0] / 9] = '\0';
  } else {
    c[0] = B[0] % 9 + '0';
    for (int i = 1; i <= B[0] / 9; i++) c[i] = '9';
    c[B[0] / 9 + 1] = '\0';
  }
  printf("%s\n", c);
  cn = strlen(c);
  for (int Ni = 1; Ni < N; Ni++) {
    if (!find(d, B[Ni], 0)) {
      d[0] = '1';
      int i = 1;
      while (!fill(d + 1, B[Ni] - 1, -i + 1)) i++;
      d[cn + i] = '\0';
    } else {
      d[cn] = '\0';
    }
    printf("%s\n", d);
    strcpy(c, d);
    cn = strlen(c);
  }
}
