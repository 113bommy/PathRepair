#include <bits/stdc++.h>
const int N = 131072;
const unsigned long long start = 43410231925;
int m, n, head[N], tot, deg[N], size[N];
struct edge {
  int to, nxt;
} e[N << 1];
void link(int x, int y) {
  e[++tot] = (edge){y, head[x]}, head[x] = tot, ++deg[x];
  e[++tot] = (edge){x, head[y]}, head[y] = tot, ++deg[y];
}
inline unsigned long long next(unsigned long long x) {
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  return x;
}
unsigned long long combine(unsigned long long l, unsigned long long r) {
  return next(start + l + r);
}
std::vector<int> roots;
int find_root(int x, int f = 0) {
  int max = 0;
  size[x] = 1;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != f) {
      size[x] += find_root(e[i].to, x);
      max = std::max(max, size[e[i].to]);
    }
  max = std::max(max, m - size[x]);
  if (max * 2 <= m) roots.emplace_back(x);
  return size[x];
}
unsigned long long hashing(int x, int f = 0) {
  unsigned long long hash = start;
  size[x] = 1;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != f) {
      hash += hashing(e[i].to, x);
      size[x] += size[e[i].to];
    }
  return next(hash);
}
int find(int x, int f = 0) {
  if (deg[x] == 1 || deg[x] == 4) return x;
  int son = 0;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != f)
      if (!son || size[e[i].to] < size[son]) son = e[i].to;
  return find(son);
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n, m = (1 << n) - 2;
  for (int i = 1, x, y; i < m; ++i) std::cin >> x >> y, link(x, y);
  std::set<unsigned long long> set;
  for (int dep = 1; dep < n; ++dep) {
    unsigned long long normal = next(start), broken = dep > 1 ? normal : 0;
    for (int i = 2; i <= n; ++i) {
      if (i == dep) {
        std::tie(normal, broken) =
            std::make_pair(combine(normal, normal), normal * 2);
      } else {
        std::tie(normal, broken) =
            std::make_pair(combine(normal, normal), combine(normal, broken));
      }
    }
    set.insert(broken);
  }
  find_root(1);
  std::set<int> answer;
  for (int root : roots) {
    ++deg[root];
    if (set.count(hashing(root))) answer.insert(find(root));
    --deg[root];
  }
  std::cout << answer.size() << '\n';
  for (int x : answer) std::cout << x << ' ';
  return 0;
}
