#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, d, f[N][20], dep[N];
vector<int> p1, p2;
inline int read() {
  int x = 0, f = 1;
  char ch = 0;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
inline int lca(int p, int q) {
  if (dep[p] < dep[q]) swap(p, q);
  for (int i = 19; i >= 0; --i)
    if (dep[f[p][i]] >= dep[q]) p = f[p][i];
  if (p == q) return p;
  for (int i = 19; i >= 0; --i)
    if (f[p][i] != f[q][i]) p = f[p][i], q = f[q][i];
  return f[p][0];
}
inline int dis(int p, int q) {
  int LCA = lca(p, q);
  return dep[p] + dep[q] - 2 * dep[LCA];
}
int D;
inline void work(int x) {
  if (p1.size() && dis(x, p1[0]) > D) {
    ++D;
    for (int i = 0; i < p2.size(); ++i)
      if (dis(p2[i], x) == D) p1.push_back(p2[i]);
    p2.clear();
    p2.push_back(x);
  } else if (p2.size() && dis(x, p2[0]) > D) {
    ++D;
    for (int i = 0; i < p1.size(); ++i)
      if (dis(p1[i], x) == D) p2.push_back(p1[i]);
    p1.clear();
    p1.push_back(x);
  } else if (p1.size() && dis(x, p1[0] == D))
    p2.push_back(x);
  else if (p2.size() && dis(x, p2[0] == D))
    p1.push_back(x);
}
int main() {
  n = read();
  p1.push_back(1);
  D = 0;
  for (int i = 1; i <= n; ++i) {
    int fa, x = i + 1;
    fa = read();
    dep[x] = dep[fa] + 1;
    f[x][0] = fa;
    for (int i = 1; i <= 19; ++i) f[x][i] = f[f[x][i - 1]][i - 1];
    work(x);
    cout << p1.size() + p2.size() << endl;
  }
}
