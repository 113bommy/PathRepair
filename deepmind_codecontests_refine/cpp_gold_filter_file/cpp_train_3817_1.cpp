#include <bits/stdc++.h>
using namespace std;
namespace cqz {
static const int GYN = 2333333;
char SZB[GYN], *S = SZB, *T = SZB;
inline char gc() {
  if (S == T) {
    T = (S = SZB) + fread(SZB, 1, GYN, stdin);
    if (S == T) return '\n';
  }
  return *S++;
}
inline int read() {
  int x = 0, g = 1;
  char ch = gc();
  for (; !isdigit(ch); ch = gc())
    if (ch == '-') g = -1;
  for (; isdigit(ch); ch = gc()) x = x * 10 - 48 + ch;
  return x * g;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline char readchar() {
  char ch = gc();
  for (; isspace(ch); ch = gc())
    ;
  return ch;
}
inline int readstr(char *s) {
  char ch = gc();
  int cur = 0;
  for (; isspace(ch); ch = gc())
    ;
  for (; !isspace(ch); ch = gc()) s[cur++] = ch;
  s[cur] = '\0';
  return cur;
}
void Print(long long *a, int s, int t) {
  for (int i = int(s); i <= int(t); ++i) printf("%lld ", a[i]);
}
void Print(int *a, int s, int t) {
  for (int i = int(s); i <= int(t); ++i) printf("%d ", a[i]);
}
void Print(char *a, int s, int t) {
  for (int i = int(s); i <= int(t); ++i) putchar(a[i]);
}
void writeln(int x) {
  write(x);
  puts("");
}
}  // namespace cqz
using namespace cqz;
int n, res1, res2;
int main() {
  n = read();
  for (int i = int(1); i <= int(n); ++i) {
    char c = gc();
    while (c != '1' && c != '0') c = gc();
    if (c == '1')
      res1++;
    else
      res2++;
  }
  if (res1) {
    putchar('1');
    for (int i = int(1); i <= int(res2); ++i) putchar('0');
  } else
    putchar('0');
}
