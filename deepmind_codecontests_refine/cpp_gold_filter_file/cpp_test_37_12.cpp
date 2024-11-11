#include <bits/stdc++.h>
using namespace std;
namespace IO_BUFF {
const int BS = (1 << 24) + 5;
char Buffer[BS], *HD, *TL;
inline int gc() {
  if (HD == TL) TL = (HD = Buffer) + fread(Buffer, 1, BS, stdin);
  return (HD == TL) ? EOF : *HD++;
}
inline int inn() {
  int x, ch;
  while ((ch = gc()) < '0' || ch > '9')
    ;
  x = ch ^ '0';
  while ((ch = gc()) >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ '0');
  return x;
}
char ss[19999999], tt[20];
int ssl, ttl;
inline int print(int x) {
  if (x < 0) ss[++ssl] = '-', x = (-x);
  if (!x) ss[++ssl] = '0';
  for (ttl = 0; x; x /= 10) tt[++ttl] = char(x % 10 + '0');
  for (; ttl; ttl--) ss[++ssl] = tt[ttl];
  return ss[++ssl] = '\n';
}
inline int Flush() {
  return fwrite(ss + 1, sizeof(char), ssl, stdout), ssl = 0, 0;
}
int read() {
  char c = getchar();
  int x = 1;
  int s = 0;
  while (c < '0' || c > '9') {
    if (c == '-') x = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
}  // namespace IO_BUFF
using namespace IO_BUFF;
const int N = 1e5;
int T, n, m, rt, a[N], b[N], c[N], f[N];
int vis[N];
void solve() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    a[i] = read();
    b[i] = read();
    c[i] = read();
  }
  for (int i = 1; i <= m; i++) {
    vis[b[i]] = 1;
  }
  int jl = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) jl = i;
  }
  for (int i = 1; i <= n; i++) {
    if (jl == i) continue;
    cout << jl << " " << i << '\n';
  }
  for (int i = 1; i <= n; i++) vis[i] = 0;
}
int main() {
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
