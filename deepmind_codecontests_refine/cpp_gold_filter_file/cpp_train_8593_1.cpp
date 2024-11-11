#include <bits/stdc++.h>
using namespace std;
int sz, ch[(100010 * 18 * 2)][2], dig[20], val[(100010 * 18 * 2)];
void add(long long x, int v) {
  for (int i = 0, ed_i = 18; i < ed_i; i++) {
    dig[18 - i - 1] = x % 10;
    x /= 10;
  }
  int u = 0;
  for (int i = 0, ed_i = 18; i < ed_i; i++) {
    int c = dig[i] % 2;
    if (!ch[u][c]) {
      ch[u][c] = ++sz;
      ch[sz][0] = ch[sz][1] = 0;
    }
    u = ch[u][c];
  }
  val[u] += v;
}
int query(char *s) {
  int len = strlen(s);
  int u = 0;
  for (int i = 0, ed_i = 18; i < ed_i; i++) {
    int c;
    if (i < 18 - len)
      c = 0;
    else {
      c = s[len + i - 18] - '0';
    }
    u = ch[u][c];
    if (!u) return 0;
  }
  return val[u];
}
int main() {
  int m;
  scanf("%d", &m);
  while (m--) {
    long long n;
    char op;
    char s[20];
    scanf(" %c", &op);
    if (op == '+') {
      scanf("%I64d", &n);
      add(n, 1);
    } else if (op == '-') {
      scanf("%I64d", &n);
      add(n, -1);
    } else {
      scanf("%s", s);
      printf("%d\n", query(s));
    }
  }
  return 0;
}
