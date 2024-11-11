#include <bits/stdc++.h>
using namespace std;
namespace SHENZHEBEI {
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
  puts("");
}
void Print(int *a, int s, int t) {
  for (int i = int(s); i <= int(t); ++i) printf("%d ", a[i]);
  puts("");
}
void Print(char *a, int s, int t) {
  for (int i = int(s); i <= int(t); ++i) putchar(a[i]);
  puts("");
}
void writeln(int x) { write(x), puts(""); }
void rewrite(int x, int y) {
  write(x), putchar(' ');
  writeln(y);
}
}  // namespace SHENZHEBEI
using namespace SHENZHEBEI;
const int N = 2010;
int fa[N], n, cnt, ok[N], rt1, rt2, Cnt;
vector<pair<int, int> > edge[N];
bitset<1010> a[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void same(int x, int y) {
  fa[find(x)] = find(y);
  fa[find(x + n)] = find(y + n);
}
void unsame(int x, int y) {
  fa[find(x)] = find(y + n);
  fa[find(x + n)] = find(y);
}
int main() {
  n = read();
  if (n == 1) return 0;
  if (n == 2) return puts("1 2"), 0;
  for (int i = int(1); i <= int(n); ++i) {
    int sum = read();
    for (int j = int(1); j <= int(sum); ++j) a[read()][i] = 1;
  }
  for (int i = int(1); i <= int(2 * n); ++i) fa[i] = i;
  for (int i = int(1); i <= int(n); ++i)
    for (int j = int(i + 1); j <= int(n); ++j) {
      int sum = (a[i] & a[j]).count();
      if (sum == 1)
        same(i, j), ++Cnt;
      else if (sum == 2)
        unsame(i, j), ++cnt, ok[i] = ok[j] = 1;
      else
        edge[sum].push_back(make_pair(i, j));
    }
  if (!cnt) {
    for (int i = int(1); i <= int(n - 1); ++i) rewrite(1, i + 1);
  } else {
    for (int sum = int(n); sum >= int(1); --sum)
      for (int i = int(0); i < int(edge[sum].size()); ++i) {
        pair<int, int> to = edge[sum][i];
        int x = to.first, y = to.second;
        if (find(x) != find(y)) {
          rewrite(x, y);
          unsame(x, y);
        }
      }
  }
}
