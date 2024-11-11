#include <bits/stdc++.h>
using namespace std;
inline char skipwhitespace() {
  char ch = getchar();
  while (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = getchar();
  return ch;
}
void gi(int &x) {
  register int c = getchar();
  x = 0;
  int sn = 1;
  for (; (c < 48 || c > 57); c = getchar())
    if (c == '-') sn = -1;
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  x *= sn;
}
void gii(long long int &x) {
  register long long int c = getchar();
  x = 0;
  long long int sn = 1;
  for (; (c < 48 || c > 57); c = getchar())
    if (c == '-') sn = -1;
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  x *= sn;
}
void wi(int n) {
  int sign = n >= 0 ? 1 : -1;
  n = n > 0 ? n : -n;
  char buf[10];
  int i = 9;
  if (!n) buf[i--] = 48;
  while (n) {
    buf[i--] = n % 10 + 48;
    n /= 10;
  }
  if (sign < 0) printf("%c", '-');
  while (++i < 10) printf("%c", buf[i]);
}
void wii(long long int n) {
  long long int sign = n >= 0 ? 1 : -1;
  n = n > 0 ? n : -n;
  char buf[25];
  long long int i = 24;
  if (!n) buf[i--] = 48;
  while (n) {
    buf[i--] = n % 10 + 48;
    n /= 10;
  }
  if (sign < 0) printf("%c", '-');
  while (++i < 25) printf("%c", buf[i]);
}
int gs(char *s) {
  char ch = skipwhitespace();
  int n = 0;
  while ((ch != '\n' && ch != ' ' && ch != '\t')) {
    s[n++] = ch;
    ch = getchar();
  }
  s[n] = 0;
  return n;
}
void ws(char *s) {
  char *p = s;
  while (*p) {
    printf("%c", *p);
    p++;
  }
}
int main() {
  long long int W, v1, v2, w1, w2, ans = 0, cnt = 1;
  gii(W);
  gii(v1);
  gii(v2);
  gii(w1);
  gii(w2);
  for (int i = 0; i <= 100000; i++)
    if (i * w1 <= W) ans = max(ans, i * v1 + ((W - i * w1) / w2) * v2);
  for (int i = 0; i <= 100000; i++)
    if (i * w2 <= W) ans = max(ans, i * v2 + ((W - i * w2) / w1) * v1);
  cout << ans << endl;
  return 0;
}
