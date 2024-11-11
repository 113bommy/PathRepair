#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 100005;
struct Union_Find_Set {
  int fa[N << 1];
  inline void init() {
    for (int i = 1; i <= 200000; ++i) fa[i] = i;
  }
  inline int Find(int x) { return x == fa[x] ? x : (fa[x] = Find(fa[x])); }
  inline bool Merge(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return 0;
    fa[x] = y;
    return 1;
  }
} S;
int n, m, a[N], b[N];
long long ans;
struct Edge {
  int x, y, z;
  bool operator<(const Edge w) const { return z > w.z; }
} e[N + N];
int le;
int main() {
  int i;
  S.init();
  read(m), read(n);
  for (i = 1; i <= m; ++i) read(a[i]);
  for (i = 1; i <= n; ++i) read(b[i]);
  for (i = 1; i <= m; ++i) {
    int t, x;
    read(t);
    while (t--) {
      ++le;
      read(x), e[le].x = x, e[le].y = i + n, e[le].z = a[i] + b[x];
      ans += e[le].z;
    }
  }
  sort(e + 1, e + le + 1);
  for (i = 1; i <= le; ++i) {
    if (S.Merge(e[i].x, e[i].y)) ans -= e[i].z;
  }
  cout << ans << '\n';
  return 0;
}
