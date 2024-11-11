#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
vector<long long> to[60];
int main() {
  int n = read();
  for (int i = (int)(1); i <= (int)(n); i++) {
    long long x = read(), y = x;
    int cnt = 0;
    while (!(x & 1)) {
      x >>= 1;
      cnt++;
    }
    to[cnt].push_back(y);
  }
  int ans = 0, pos;
  for (int i = (int)(0); i <= (int)(59); i++)
    if (to[i].size() > ans) {
      ans = to[i].size();
      pos = i;
    }
  writeln(n - ans);
  for (int i = (int)(0); i <= (int)(59); i++)
    if (i != pos)
      for (auto j : to[i]) wri(j);
}
