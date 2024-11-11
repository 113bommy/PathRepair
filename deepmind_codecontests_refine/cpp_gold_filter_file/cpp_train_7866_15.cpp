#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
long long n, m, i, j, a[100005], b[100005], s0, s1;
long long qp(long long x, long long y) {
  if (!y) return 1;
  long long z = qp(x, y / 2);
  z = z * z % m;
  if (y & 1) z = z * x % m;
  return z % m;
}
int main() {
  readll(m);
  readll(n);
  for (i = 1; i <= n; i++) {
    readll(a[i]);
    s0 += a[i];
    s1 += a[i] * a[i];
    s0 %= m;
    s1 %= m;
  }
  if (n == 1) {
    writell(a[1]);
    writes(" 0");
    return 0;
  }
  stable_sort(a + 1, a + n + 1);
  for (i = 2; i <= n; i++) {
    long long d = a[i] - a[1] + m;
    d %= m;
    long long x = (s0 - n * (n - 1) / 2 % m * d % m + m) % m * qp(n, m - 2) % m;
    long long ans = n * x % m * x % m;
    ans = (ans + n * (n - 1) % m * d % m * x % m) % m;
    ans = (ans + n * (n - 1) * (2 * n - 1) / 6 % m * d % m * d % m) % m;
    if (ans == s1) {
      b[1] = x;
      for (j = 2; j <= n; j++) {
        b[j] = b[j - 1] + d;
        b[j] %= m;
      }
      stable_sort(b + 1, b + n + 1);
      bool flag = 1;
      for (j = 1; j <= n; j++) {
        if (a[j] != b[j]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        writell(x);
        printf(" ");
        writell(d);
        return 0;
      }
    }
  }
  writes("-1");
  return 0;
}
