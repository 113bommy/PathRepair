#include <bits/stdc++.h>
void read(int &x) {
  x = 0;
  int flag = 1;
  char ch = ' ';
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= flag;
}
void read(long long &x) {
  x = 0;
  int flag = 1;
  char ch = ' ';
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= flag;
}
using namespace std;
const int maxn = 1000010;
char a[maxn], b[maxn], s[maxn * 2];
int n, suf[maxn * 2], pre[maxn * 2];
void calc_suf(char *s) {
  int len = strlen(s);
  suf[0] = 0;
  for (int i = 1, j = 0; i < len; i++) {
    while (j && s[j] != s[i]) j = suf[j - 1];
    if (s[j] == s[i]) j++;
    suf[i] = j;
  }
}
void calc_pre(char *s) {
  pre[0] = 0;
  int l = 0, r = 0, len = strlen(s);
  for (int i = 1; i <= len - 1; i++) {
    if (r < i) {
      l = r = i;
      for (; r < len && s[r] == s[r - i]; r++)
        ;
      r--, pre[i] = r - l + 1;
    } else {
      int k = i - l;
      if (pre[k] < r - i + 1)
        pre[i] = pre[k];
      else {
        l = i;
        for (; r < len && s[r] == s[r - i]; r++)
          ;
        r--, pre[i] = r - l + 1;
      }
    }
  }
}
int main() {
  gets(a), gets(b);
  int n = strlen(a), tmp = strlen(b);
  if (n != tmp) {
    puts("-1 -1");
    return 0;
  }
  reverse(a, a + n);
  for (int i = 0; i <= n - 1; i++) s[i] = a[i];
  s[n] = '$';
  for (int i = n + 1; i <= n + n; i++) s[i] = b[i - n - 1];
  s[n + n + 1] = '|';
  calc_suf(s);
  reverse(a, a + n);
  for (int i = 0; i <= n - 1; i++) s[i] = b[i];
  for (int i = n + 1; i <= n + n; i++) s[i] = a[i - n - 1];
  calc_pre(s);
  reverse(b, b + n);
  int ri = -1, rj = -1;
  for (int i = 1; i <= n - 1; i++) {
    if (a[i - 1] != b[i - 1]) break;
    int matchleft = suf[2 * n - i], matchright = pre[n + i + 1];
    if (matchleft && matchleft + matchright + i >= n) {
      if (ri < i - 1)
        ri = i - 1, rj = n - matchleft;
      else if (ri == i - 1)
        rj = min(rj, n - matchleft);
    }
  }
  printf("%d %d\n", ri, rj);
  return 0;
}
