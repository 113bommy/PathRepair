#include <bits/stdc++.h>
using namespace std;
template <class T>
T& umax(T& a, const T& b) {
  if (b > a) a = b;
}
template <class T>
T& umin(T& a, const T& b) {
  if (b < a) a = b;
}
const int N = 1 << 7;
int n, m;
std::vector<int> g[N];
bool f[N], p[N];
std::vector<int> q;
int cnt;
bool query(int u) {
  if (cnt == 0) return false;
  --cnt, p[u] = true;
  cout << "? " << u << '\n';
  fflush(stdout);
  int q;
  cin >> q;
  f[u] = true;
  while (q--) {
    int v;
    cin >> v;
    if (!f[v]) {
      f[v] = true;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  return true;
}
int ans;
void ran(int u) {
  if (g[u].size() == 2) {
    ans = u;
    return;
  }
  if (g[u].size() == 1) return;
  for (auto v : g[u]) {
    if (p[v]) continue;
    query(v);
    q.push_back(v);
    ran(v);
    break;
  }
}
void force(int u, int h) {
  if (ans) return;
  if (h < 0) return;
  bool res = query(u);
  if (!res) {
    ans = u;
    return;
  }
  if (g[u].size() == 2) {
    ans = u;
    return;
  }
  for (auto v : g[u])
    if (!p[v]) force(v, h - 1);
}
int main() {
  for (auto i = 0, i_n = N; i < i_n; ++i) g[i].reserve(3);
  int _, __ = 1;
  for (std::cin >> _; _; --_, ++__) {
    int h;
    cin >> h;
    n = (1 << h) - 1;
    for (auto i = 1, i_n = n + 1; i < i_n; ++i) g[i].clear();
    memset(f, 0x00, sizeof f);
    memset(p, 0x00, sizeof p);
    q.clear();
    ans = 0;
    cnt = 16;
    m = 1;
    f[m] = true;
    query(m);
    q.push_back(m);
    ran(m);
    reverse(q.begin(), q.end());
    ran(m);
    while (!ans) {
      if (q.size() >= 5) break;
      q.resize(q.size() / 2 + 1);
      int m = q.back();
      for (auto v : g[m])
        if (!p[v]) m = v;
      q.push_back(m);
      query(m);
      ran(m);
    }
    if (!ans) {
      q.resize(q.size() / 2 + 1);
      int m = q.back();
      for (auto v : g[m])
        if (!p[v]) m = v;
      force(m, h - q.size());
    }
    cout << "! " << ans << '\n';
  }
  return 0;
}
