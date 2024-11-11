#include <bits/stdc++.h>
using namespace std;
int N[5010], n, f[5010], tot;
char s[5010];
bool M[5010];
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
int Get(char *s, int n) {
  int X = 0;
  for (int i = 1; i < n;) {
    int k = i + 2;
    for (; k <= n && s[k] == s[k - 2]; k++)
      ;
    X ^= f[k - i];
    i = k - 1;
  }
  return X;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  f[1] = 0;
  f[2] = 0;
  for (int i = 3; i <= n; i++) {
    for (int j = 0; j <= i; j++) M[i] = 0;
    for (int j = 2; j < i; j++) M[f[j - 1] ^ f[i - j]] = 1;
    for (int j = 0; j <= i; j++)
      if (!M[j]) {
        f[i] = j;
        break;
      }
  }
  if (Get(s, n)) {
    printf("First\n");
    for (int i = 2; i < n; i++)
      if (s[i - 1] == s[i + 1]) {
        int X = Get(s, i - 1) ^ Get(s + i, n - i);
        if (X == 0) {
          printf("%d\n", i);
          break;
        }
      }
  } else {
    printf("Second\n");
  }
  return 0;
}
