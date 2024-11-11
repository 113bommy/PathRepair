#include <bits/stdc++.h>
using namespace std;
template <typename T>
T scani(T &n) {
  n = 0;
  bool negative = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') negative = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = n * 10 + c - 48;
    c = getchar();
  }
  if (negative) n = ~(n - 1);
  return n;
}
template <typename T>
void write(T n, int type = true) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (!n) {
    putchar('0');
    if (type == 32)
      putchar(' ');
    else if (type)
      putchar('\n');
    return;
  }
  char buff[22];
  int len = 0;
  while (n) buff[len++] = n % 10 + 48, n /= 10;
  for (int i = len - 1; i >= 0; i--) putchar(buff[i]);
  if (type == 32)
    putchar(' ');
  else if (type)
    putchar('\n');
}
int scans(char *a) {
  int i = 0;
  char c = 0;
  while (c < 33) c = getchar();
  while (c > 33) {
    a[i++] = c;
    c = getchar();
  }
  a[i] = 0;
  return i;
}
const int MOD = 1e9 + 7;
const int maxn = 5000;
int main() {
  int n;
  scani(n);
  int cnt = 1;
  for (int i = 2; i < sqrt(1.L * n); ++i) {
    if (n % i == 0) cnt += 2;
  }
  write(cnt + (sqrt(n) * sqrt(n) == n));
  return 0;
}
