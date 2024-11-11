#include <bits/stdc++.h>
using namespace std;
struct READ {
  inline char read() {
    const int LEN = 1 << 18 | 1;
    static char buf[LEN], *s, *t;
    return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)),
           s == t ? -1 : *s++;
  }
  inline READ &operator>>(char *s) {
    char ch;
    while (isspace(ch = read()) && ~ch)
      ;
    while (!isspace(ch) && ~ch) *s++ = ch, ch = read();
    *s = '\0';
    return *this;
  }
  inline READ &operator>>(string &s) {
    s = "";
    char ch;
    while (isspace(ch = read()) && ~ch)
      ;
    while (!isspace(ch) && ~ch) s += ch, ch = read();
    return *this;
  }
  template <typename _Tp>
  inline READ &operator>>(_Tp &x) {
    char ch, flag;
    for (ch = read(), flag = 0; !isdigit(ch) && ~ch; ch = read())
      flag |= ch == '-';
    for (x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
    flag && (x = -x);
    return *this;
  }
} in;
const int N = 2e5 + 50;
int win(long long s, long long e) {
  if (e & 1) {
    if (s & 1) return 0;
    return 1;
  } else {
    if (s * 2 > e) {
      if (s & 1) return 1;
      return 0;
    } else if (s * 4 > e)
      return 1;
    else
      return win(s, e / 4);
  }
}
int lose(long long s, long long e) {
  if (s * 2 > e) return 1;
  return win(s, e / 2);
}
int las[2], now[2];
int main() {
  int t;
  in >> t;
  las[0] = 1;
  while (t--) {
    long long s, e;
    in >> s >> e;
    now[0] = now[1] = 0;
    if (las[0]) {
      now[0] |= lose(s, e);
      now[1] |= win(s, e);
    }
    if (las[1]) {
      now[0] |= !lose(s, e);
      now[1] |= !win(s, e);
    }
    las[0] = now[0], las[1] = now[1];
  }
  printf("%d %d\n", now[0], now[1]);
  return 0;
}
