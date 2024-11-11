#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int a = 0;
  char c = getchar(), f = 1;
  for (; c < '0' or c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (; '0' <= c and c <= '9'; c = getchar())
    a = (a << 3) + (a << 1) + (c ^ 48);
  return a * f;
}
inline void writeint(long long x) {
  if (x > 9) writeint(x / 10);
  putchar((x % 10) ^ 48);
}
template <class T>
void getMax(T &a, const T &b) {
  if (a < b) a = b;
}
template <class T>
void getMin(T &a, const T &b) {
  if (b < a) a = b;
}
const int MaxN = 100005;
set<pair<int, int>> v[MaxN];
void add(int x, pair<int, int> p) {
  auto now = v[x].lower_bound(p);
  if (now == v[x].begin() or (--now)->second < p.second) {
    now = v[x].insert(p).first;
    ++now;
    while (now != v[x].end() and p.second >= now->second) v[x].erase(now++);
  }
}
int main() {
  int n = readint(), m = readint();
  for (int i = 1; i <= n; ++i) v[i].insert(make_pair(-1, 0));
  for (int i = 1, a, b, c; i <= m; ++i) {
    a = readint(), b = readint(), c = readint();
    auto it = v[a].lower_bound(make_pair(c, 0));
    if (it != v[a].begin()) add(b, make_pair(c, (--it)->second + 1));
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    auto it = v[i].end();
    getMax(ans, (--it)->second);
  }
  writeint(ans), putchar('\n');
  return 0;
}
