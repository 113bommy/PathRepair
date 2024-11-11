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
const int N = 600100;
int dfn[N], u[N], v[N], d[N], n, cnt;
void merge(int i, int j) { u[++cnt] = i, v[cnt] = j; }
void solve(int l, int r, int s, int t) {
  if (l > r) return;
  if (l == r) {
    for (int i = int(s); i <= int(t); ++i)
      for (int j = int(i + 1); j <= int(t); ++j) merge(i, j);
    return;
  }
  for (int i = int(t - d[l] + 1); i <= int(t); ++i)
    for (int j = int(i + 1); j <= int(t); ++j) merge(i, j);
  for (int i = int(s); i <= int(t - d[l]); ++i)
    for (int j = int(t - d[l] + 1); j <= int(t); ++j) merge(i, j);
  int nxtl = s + d[r] - d[r - 1], nxtr = t - d[l];
  for (int i = int(r); i >= int(l); --i) d[i] -= d[l];
  solve(l + 1, r - 1, nxtl, nxtr);
}
int main() {
  n = read();
  for (int i = int(1); i <= int(n); ++i) d[i] = read();
  solve(1, n, 1, d[n] + 1);
  writeln(cnt);
  for (int i = int(1); i <= int(cnt); ++i) printf("%d %d\n", u[i], v[i]);
}
