#include <bits/stdc++.h>
const int oo = 2139063143;
const int N = 1010000;
const int P = 1000000007;
using namespace std;
template <typename T>
inline void sc(T &x) {
  x = 0;
  static int p;
  p = 1;
  static char c;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c - 48);
    c = getchar();
  }
  x *= p;
}
template <typename T>
inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void pr(T x) {
  print(x), putchar('\n');
}
int a[N];
bool check(int l1, int r1, int l2) {
  for (int i = l1, j = l2; i <= r1; i++, j++)
    if (a[i] != a[j]) return 0;
  return 1;
}
int n;
void del(int l, int r) {
  for (int i = r + 1, j = l; i <= n; i++, j++) a[j] = a[i];
}
char s[N];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int len = 1;
  for (int i = 1; i <= n; i++) a[i] = s[i] - 'a' + 1;
  while (len <= min(482, n)) {
    for (int i = 1; i <= n - len * 2 + 1; i++)
      if (check(i, i + len - 1, i + len)) {
        del(i, i + len - 1), n -= len, len = 0;
        break;
      }
    ++len;
  }
  for (int i = 1; i <= n; i++) putchar(a[i] + 'a' - 1);
  return 0;
}
