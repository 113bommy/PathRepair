#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1111;
int n, m, a[N];
struct {
  void add(int id, int value) {
    if (a[0].second == id) {
      a[0].first = std::min(a[0].first, value);
    } else if (a[1].first > value) {
      a[1] = {value, id};
    }
    if (a[0].first > a[1].first) {
      std::swap(a[0], a[1]);
    }
  }
  std::pair<int, int> a[2] = {{INF, -1}, {INF, -1}};
} b[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int k, first, s = 0;
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &first);
      s ^= 1 << first - 1;
    }
    ++a[s];
  }
  for (int i = 0; i <= 8; ++i)
    for (int j = 0; j <= 511; ++j)
      if (j >> i & 1) a[j] += a[j ^ 1 << i];
  for (int i = 1; i <= m; ++i) {
    int v, k, first, s = 0;
    scanf("%d%d", &v, &k);
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &first);
      s ^= 1 << first - 1;
    }
    b[s].add(i, v);
  }
  pair<int, int> ans(-1, -1);
  int first, second;
  for (int i = 0; i <= 511; ++i)
    for (int j = 0; j <= 511; ++j)
      for (int u = 0; u <= 1; ++u)
        for (int v = 0; v <= 1; ++v) {
          if (b[i].a[u].first == INF || b[j].a[v].first == INF) continue;
          if (b[i].a[u].second != b[j].a[v].second) {
            int w = b[i].a[u].first + b[j].a[v].first;
            if (pair<int, int>(a[i | j], -w) > ans) {
              ans = pair<int, int>(a[i | j], -w);
              first = b[i].a[u].second, second = b[j].a[v].second;
            }
          }
        }
  printf("%d %d\n", first, second);
}
