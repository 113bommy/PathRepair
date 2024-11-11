#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
int qread() {
  int w = 1, c, ret;
  while ((c = getchar()) > '9' || c < '0') w = (c == '-' ? -1 : 1);
  ret = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + c - '0';
  return ret * w;
}
int readc() {
  char c;
  while ((c = getchar()) == ' ' || c == '\n')
    ;
  return c;
}
const int MAXN = 1e5 + 3, MAXM = 1e2 + 3;
int n, m, b, f, x;
int S[MAXM], L[MAXM];
bool P[MAXN];
int find(int len) {
  int cnt = b;
  for (int i = 0; i <= n + f; i++) {
    if (!P[i])
      cnt++;
    else
      cnt = 0;
    if (cnt == b + len + f) {
      for (int j = 1; j <= len; j++) P[i - f - j + 1] = true;
      return i - len - f + 1;
    }
  }
  return -1;
}
int main() {
  n = qread(), b = qread(), f = qread(), m = qread();
  for (int i = 1; i <= m; i++) switch (readc()) {
      case '1':
        L[i] = x = qread(), printf("%d\n", S[i] = find(x));
        break;
      case '2':
        x = qread();
        if (S[x] != -1)
          for (int i = 1; i <= L[x]; i++) P[S[x] + i - 1] = false;
    }
  return 0;
}
