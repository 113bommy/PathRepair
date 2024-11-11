#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x *= 10;
    x += ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void read(char *s, int &ts) {
  char x = getchar();
  while (!(x >= 'a' && x <= 'z')) x = getchar();
  while (x >= 'a' && x <= 'z') s[++ts] = x, x = getchar();
}
int n, top;
long long ans;
int a[100010];
int main() {
  n = read();
  ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    x = read();
    if (top > 1 && a[top - 1] >= a[top] && x >= a[top]) {
      ans += min(a[top - 1], x);
      top--;
    }
    a[++top] = x;
  }
  sort(a + 1, a + top + 1);
  for (int i = 1; i <= top - 2; i++) ans += a[i];
  printf("%I64d\n", ans);
  return 0;
}
