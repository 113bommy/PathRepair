#include <bits/stdc++.h>
using uint = unsigned int;
constexpr uint Maxn(200000);
namespace IOManager {
using uint = unsigned int;
constexpr uint FILESZ(4200020);
unsigned char buf[FILESZ];
const unsigned char* ibuf = buf;
struct IOManager {
  IOManager() { buf[fread(buf, 1u, FILESZ, stdin)] = ' '; }
  ~IOManager() {}
  template <class _Tp>
  inline operator _Tp() {
    _Tp s = 0u;
    unsigned char neg = 0u;
    for (; !isdigit(*ibuf); ++ibuf) (*ibuf == 45u) && (neg = 1u);
    for (; isdigit(*ibuf); ++ibuf) s = (_Tp)(s * 10u + *ibuf - 48u);
    return neg ? -(_Tp)s : s;
  }
  template <class _Tp>
  inline _Tp operator()(_Tp& rhs) {
    _Tp s = 0u;
    unsigned char neg = 0u;
    for (; !isdigit(*ibuf); ++ibuf) (*ibuf == 45u) && (neg = 1u);
    for (; isdigit(*ibuf); ++ibuf) s = (_Tp)(s * 10u + *ibuf - 48u);
    return rhs = neg ? -(_Tp)s : s;
  }
  inline operator uint() {
    uint s = 0u;
    for (; !isdigit(*ibuf); ++ibuf)
      ;
    for (; isdigit(*ibuf); ++ibuf) s = (uint)(s * 10u + *ibuf - 48u);
    return s;
  }
};
}  // namespace IOManager
IOManager::IOManager io;
struct Edge {
  uint v, nxt;
  Edge() : v(0), nxt(0) {}
  Edge(const uint& to, const uint& nx) : v(to), nxt(nx) {}
} e[(Maxn + 5u) << 1u];
uint cnt = 1;
uint las[Maxn + 1u];
unsigned char vis[Maxn + 1u];
int s[Maxn | 1u];
int v[(Maxn + 5u) << 1u];
inline void AddEdge(const uint& x, const uint& y) {
  e[++cnt] = Edge(y, las[x]);
  las[x] = cnt;
  e[++cnt] = Edge(x, las[y]);
  las[y] = cnt;
}
void calc(const uint& now) {
  vis[now] = 1u;
  for (uint o = las[now], _; o; o = e[o].nxt)
    if (!vis[_ = e[o].v]) calc(_), s[now] += s[_], v[o] = s[_];
}
int main() {
  const uint n = io;
  int sum = 0;
  for (uint i = 1u; i <= n; ++i) sum += io(s[i]);
  if (sum) return puts("Impossible"), 0;
  for (uint m = io, u; m; --m) u = io, AddEdge(u, io);
  calc(1u);
  puts("Possible");
  for (uint i = 2u; i <= cnt; i += 2u)
    printf("%d\n", v[i | 1u] ? -v[i | 1u] : v[i]);
  return 0;
}
