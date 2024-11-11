#include <bits/stdc++.h>
using namespace std;
int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
int n, k;
char s[105];
void init() {
  n = read(), k = read();
  scanf("%s", s);
}
void solve() {
  int st;
  for (st = 1; st < n; st++) {
    int flag = 1;
    for (int j = 0; j < n - st; ++j)
      if (s[st + j] != s[j]) {
        flag = 0;
        break;
      }
    if (flag) break;
  }
  if (st == n) {
    for (int i = 0; i < k; ++i) printf("%s", s);
  } else {
    for (int i = 0; i < k - 1; ++i)
      for (int j = 0; j < st; ++j) putchar(s[j]);
    for (int i = st; i < n; ++i) putchar(s[i]);
  }
  printf("\n");
}
int main() {
  init();
  solve();
  return 0;
}
