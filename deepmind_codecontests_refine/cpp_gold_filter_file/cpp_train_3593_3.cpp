#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
template <typename T>
bool chkmin(T &a, T b) {
  return b <= a ? a = b, true : false;
}
template <typename T>
bool chkmax(T &a, T b) {
  return b >= a ? a = b, true : false;
}
template <class T>
void read(T &x) {
  char c;
  int flag = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= flag;
}
template <class T>
void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  static char s[20];
  int top = 0;
  while (x) s[++top] = x % 10 + '0', x /= 10;
  if (top == 0) putchar('0');
  while (top) putchar(s[top--]);
}
const int MAXN = 30;
int a[MAXN];
int N;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  read(N);
  int odd = 0;
  for (int i = 1; i <= N; ++i) {
    read(a[i]);
    if (a[i] & 1) {
      if (odd)
        odd = -1;
      else
        odd = i;
    }
  }
  if (odd == -1) {
    write(0), putchar('\n');
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= a[i]; ++j) putchar(i + 'a' - 1);
    }
    putchar('\n');
  } else {
    int Gcd = 0;
    for (int i = 1; i <= N; ++i) Gcd = gcd(Gcd, a[i]);
    write(Gcd), putchar('\n');
    if (odd == 0) Gcd /= 2;
    for (int k = 1; k <= Gcd; ++k) {
      for (int i = 1; i <= N; ++i) {
        if (a[i] & 1) continue;
        for (int j = 1; j <= a[i] / Gcd / 2; ++j) putchar(i + 'a' - 1);
      }
      if (odd) {
        for (int i = 1; i <= a[odd] / Gcd; ++i) putchar(odd + 'a' - 1);
      }
      for (int i = N; i >= 1; --i) {
        if (a[i] & 1) continue;
        for (int j = 1; j <= a[i] / Gcd / 2; ++j) putchar(i + 'a' - 1);
      }
    }
    putchar('\n');
  }
  return 0;
}
