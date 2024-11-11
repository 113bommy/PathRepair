#include <bits/stdc++.h>
using namespace std;
const int N = 711, M = 1e6;
struct bint {
  vector<int> a{1};
  void operator*=(int x) {
    int i, c = 0;
    for (i = 0; i < a.size(); ++i) {
      int t = c + a[i] * x;
      a[i] = t % M;
      c = t / M;
    }
    if (c) a.push_back(c);
  }
  void out() const {
    cout << a.back();
    for (int i = a.size() - 2; ~i; --i) {
      auto t = to_string(a[i]);
      cout << string(6 - t.size(), 48) + t;
    }
    puts("");
  }
} s;
int reduce(int c, vector<int> &p, vector<int> &n) {
  sort(p.begin(), p.end());
  for (int i = 1; i < p.size(); ++i) s *= p[i];
  if (n.empty()) {
    if (!c) return p.empty() ? 0 : -p[0];
    if (p.size()) s *= p[0];
    return 1 + c;
  }
  sort(n.begin(), n.end());
  if (!c && n[0] == -2) {
    if (p.empty()) p = {3}, n.pop_back();
    for (int i : n) s *= 3;
    return -p[0];
  }
  if (p.size()) s *= p[0];
  for (int x : n)
    if (c + 1 < -x)
      ++c, s *= -x;
    else
      s *= 1 - x;
  return 1 + c;
}
vector<int> e[N], p[N][2];
int dfs(int v, int fa) {
  int c = 0, t;
  for (int i : e[v])
    if (i != fa)
      if (t = dfs(i, v))
        p[v][t < 0].push_back(t);
      else
        ++c;
  return reduce(c, p[v][0], p[v][1]);
}
int main() {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  int r = dfs(1, 0);
  s *= r < 0 ? 1 - r : r;
  s.out();
  return 0;
}
