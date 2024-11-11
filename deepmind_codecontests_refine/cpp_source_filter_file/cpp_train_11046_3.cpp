#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  register char ch;
  register bool fl = 0;
  while (ch = getchar(), ch < 48 || 57 < ch) fl ^= ch == '-';
  x = (ch & 15);
  while (ch = getchar(), 47 < ch && ch < 58)
    x = (x << 1) + (x << 3) + (ch & 15);
  if (fl) x = -x;
}
template <typename T>
inline void print(T x, char c = '\n') {
  static int buf[40];
  if (x == 0) {
    putchar('0');
    putchar(c);
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
  while (buf[0]) putchar((char)buf[buf[0]--]);
  putchar(c);
}
const int maxn = 100010;
int n, m, t;
char s[1000010];
int bit[maxn];
std::map<int, int> cnt;
long long ans;
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1), t = strlen(s + 1);
    for (int j = 1; j <= t; j++) bit[i] ^= 1 << s[j];
  }
  for (int i = 1; i <= n; i++) {
    ans += cnt[bit[i]];
    for (int j = 0; j < 26; j++) ans += cnt[bit[i] ^ (1 << j)];
    cnt[bit[i]]++;
  }
  print(ans);
  return 0;
}
