#include <bits/stdc++.h>
using namespace std;
long long read() {
  char c = getchar();
  long long u = 0, f = 1;
  while (c != '-' && (c < '0' || '9' < c)) c = getchar();
  if (c == '-') {
    f = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    u = u * 10 + c - '0';
    c = getchar();
  }
  return u * f;
}
char readc() {
  for (;;) {
    char c = getchar();
    if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z') return c;
  }
}
int read_digit() {
  for (;;) {
    char c = getchar();
    if ('0' <= c && c <= '9') return c - '0';
  }
}
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
template <typename T>
inline void updmax(T &a, T b) {
  if (b > a) a = b;
}
template <typename T>
inline void updmin(T &a, T b) {
  if (b < a) a = b;
}
inline void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
char a[300010], b[300010], c[300010];
int main() {
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  int n = strlen(a + 1);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1, greater<char>());
  int p1 = 1, p2 = 1;
  int u1 = (n + 1) / 2, u2 = n / 2;
  int q1 = 1, q2 = n;
  for (int i = 1; i <= (n + 1) / 2; i++) {
    if (a[p1] > b[p2])
      c[q2--] = a[u1--];
    else
      c[q1++] = a[p1++];
    if (q1 > q2) break;
    if (a[p1] > b[p2])
      c[q2--] = b[u2--];
    else
      c[q1++] = b[p2++];
  }
  for (int i = 1; i <= n; i++) putchar(c[i]);
  return 0;
}
