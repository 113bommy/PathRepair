#include <bits/stdc++.h>
using namespace std;
void mswap(int &x, int &y) { x ^= y ^= x ^= y; }
void read(int &x) {
  x = 0;
  char ch = getchar();
  int pd = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      pd = -pd;
    }
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= pd;
}
void write(const int &x) {
  char f[100001];
  int s = 0;
  int tmp = x;
  if (tmp == 0) {
    putchar('0');
    return;
  }
  if (tmp < 0) {
    tmp = -tmp;
    putchar('-');
  }
  while (tmp > 0) {
    f[s++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (s > 0) {
    putchar(f[--s]);
  }
}
const int N = 1e5 + 10;
char s[N], ss[N];
bitset<N> a[30], now;
int main() {
  gets(s + 1);
  int st = strlen(s + 1);
  for (register int i = 1; i <= st; ++i) {
    a[s[i] - 'a'][i] = 1;
  }
  int n;
  read(n);
  for (register int i = 1; i <= n; ++i) {
    int aa;
    read(aa);
    if (aa == 1) {
      int l;
      read(l);
      char ch = getchar();
      while (ch < 'a' || ch > 'z') {
        ch = getchar();
      }
      a[s[l] - 'a'][l] = 0;
      a[ch - 'a'][l] = 1;
      s[l] = ch;
    } else {
      int l, r;
      read(l);
      read(r);
      scanf("%s", ss + 1);
      int len = strlen(ss + 1);
      now.set();
      for (register int j = 1; j <= len; ++j) {
        now &= (a[ss[j] - 'a'] >> j);
      }
      int ll = (now >> (l - 1)).count();
      int rr = (now >> (r - len + 2)).count();
      ll = (ll > rr ? ll : rr);
      write(ll - rr);
      puts("");
    }
  }
}
