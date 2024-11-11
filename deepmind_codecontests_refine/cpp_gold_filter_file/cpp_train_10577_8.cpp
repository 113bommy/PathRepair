#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int read(T& x) {
  x = 0;
  char c = getchar(), f = 1;
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    if (c == -1) return -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  x *= f;
  return 1;
}
template <typename T, typename... Args>
inline int read(T& x, Args&... args) {
  return read(x) + read(args...);
}
template <typename T>
inline int write(T x) {
  if (x < 0) return putchar('-') & write((~x) + 1);
  if (x / 10) return write(x / 10) & putchar(x % 10 | 48);
  return putchar(x | 48);
}
template <typename T>
inline int write(T x, char c) {
  return write(x) + putchar(c);
}
int n;
char s[100005];
struct BIT {
  int tr[100005];
  inline void update(int i, int delta) {
    for (; i < 100005; i += ((i) & (-(i)))) tr[i] += delta;
  }
  inline int query(int i) {
    int ans = 0;
    for (; i; i -= ((i) & (-(i)))) ans += tr[i];
    return ans;
  }
  inline int query(int l, int r) { return query(r) - query(l - 1); }
} tr[4][11][11];
inline int idc(char c) {
  if (c == 'A') return 0;
  if (c == 'T') return 1;
  if (c == 'G') return 2;
  if (c == 'C') return 3;
  cout << "cfnmsl" << endl;
  exit(0);
  return -1;
}
inline int gotchar() {
  char c = getchar();
  while (!(~idc(c))) c = getchar();
  return c;
}
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int j = 1; j <= 10; j++)
    for (int i = 1; i <= n; i++) tr[idc(s[i])][j][i % j].update(i, 1);
  int q;
  read(q);
  while (q--) {
    int ty;
    read(ty);
    if (ty == 1) {
      int pos;
      read(pos);
      char c = gotchar();
      for (int j = 1; j <= 10; j++) {
        tr[idc(s[pos])][j][pos % j].update(pos, -1);
        tr[idc(c)][j][pos % j].update(pos, 1);
      }
      s[pos] = c;
    } else {
      int l, r;
      read(l, r);
      char e[11];
      scanf("%s", e);
      int len = strlen(e), ans = 0;
      for (int i = 0; i < len; i++)
        ans += tr[idc(e[i])][len][(l + i) % len].query(l, r);
      write(ans, '\n');
    }
  }
}
