#include <bits/stdc++.h>
unsigned long long lca(unsigned long long a, unsigned long long b) {
  while (__builtin_clz(a) < __builtin_clz(b)) a >>= 1;
  while (__builtin_clz(b) < __builtin_clz(a)) b >>= 1;
  while (a != b) a >>= 1, b >>= 1;
  return a;
}
std::map<unsigned long long, std::map<unsigned long long, unsigned long long>>
    m;
unsigned long long getnext(unsigned long long par, unsigned long long dest) {
  unsigned long long l = par << 1;
  unsigned long long r = l ^ 1;
  if (lca(dest, l) == par)
    return r;
  else
    return l;
}
void addup(unsigned long long top, unsigned long long to,
           unsigned long long add) {
  while (top < to) {
    unsigned long long next = getnext(top, to);
    m[top][next] += add;
    top = next;
  }
}
unsigned long long cost(unsigned long long p, unsigned long long ne) {
  auto it = m.find(p);
  if (it != m.end()) {
    auto it2 = it->second.find(ne);
    if (it2 != it->second.end()) return it2->second;
  }
  return 0;
}
unsigned long long sumdown(unsigned long long top, unsigned long long to) {
  unsigned long long s = 0;
  while (top < to) {
    unsigned long long next = getnext(top, to);
    s += cost(top, next);
    top = next;
  }
  return s;
}
int main() {
  std::ios::sync_with_stdio(false);
  int q;
  std::cin >> q;
  while (q--) {
    int c;
    std::cin >> c;
    if (c == 1) {
      unsigned long long v, u, w;
      std::cin >> v >> u >> w;
      unsigned long long lowca = lca(v, u);
      addup(lowca, v, w);
      addup(lowca, u, w);
    } else {
      unsigned long long u, v;
      std::cin >> u >> v;
      unsigned long long lowca = lca(u, v);
      std::cout << sumdown(lowca, u) + sumdown(lowca, v) << "\n";
    }
  }
  return 0;
}
