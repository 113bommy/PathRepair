#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, sum1, sum2;
int x, y;
char s[N], t[N];
int nxt[N];
void get_next() {
  int now = 0, i = 2;
  nxt[1] = 0;
  while (i <= n) {
    if (t[now + 1] == t[i]) {
      nxt[i++] = ++now;
    } else if (now) {
      now = nxt[now];
    } else {
      nxt[i++] = 0;
    }
  }
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    sum1 += s[i] - '0';
  }
  scanf("%s", t + 1);
  m = strlen(t + 1);
  for (int i = 1; i <= m; i++) {
    sum2 += t[i] - '0';
  }
  int len = 0;
  get_next();
  len = nxt[m];
  x = 0, y = 0;
  for (int i = 1; i <= len; i++) {
    if (t[i] == '1') x++;
  }
  y = len - x;
  int k = 0;
  if (n < m || sum1 < sum2 || (n - sum1) < (m - sum2)) {
    printf("%s\n", s);
  } else {
    if (sum2 == 0 || sum2 == m) {
      for (int i = 1; i <= n - sum1; i++) {
        printf("0");
      }
      for (int i = 1; i <= sum1; i++) {
        printf("1");
      }
      printf("\n");
    } else {
      k = min((sum1 - x) / (sum2 - x), (n - sum1 - y) / (m - sum2 - y));
      for (int i = 1; i <= len; i++) {
        printf("%c", t[i]);
      }
      for (int i = 1; i <= k; i++) {
        for (int j = len + 1; j <= m; j++) {
          printf("%c", t[j]);
        }
      }
      for (int i = 1; i <= (sum1 - x - k * (sum2 - x)); i++) {
        printf("1");
      }
      for (int i = 1; i <= (n - sum1 - y - k * (m - sum2 - y)); i++) {
        printf("0");
      }
      printf("\n");
    }
  }
  return 0;
}
