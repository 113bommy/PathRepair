#include <bits/stdc++.h>
using namespace std;
template <class T>
T gi() {
  T x = 0;
  bool f = 0;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') f = 1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f ? -x : x;
}
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, k, c[N];
vector<pair<int, int> > in[N], out[N];
set<int> pls;
set<pair<int, int> > v;
void add(int x, int y) {
  for (; x <= n; x += (x & (-x))) (c[x] += y) %= Mod;
}
int sum(int x) {
  int res = 0;
  for (; x; x -= (x & (-x))) (res += c[x]) %= Mod;
  return res;
}
int main() {
  n = gi<int>(), m = gi<int>(), k = gi<int>();
  for (int i = 1; i <= k; i++) {
    int X1 = gi<int>(), Y1 = gi<int>(), X2 = gi<int>(), Y2 = gi<int>();
    in[Y1].push_back(make_pair(X1, X2));
    out[Y2 + 1].push_back(make_pair(X1, X2));
  }
  in[++m].push_back(make_pair(1, n - 1));
  add(1, 1);
  pls.insert(1);
  v.insert(make_pair(0, 0));
  for (int i = 1; i <= m; i++)
    if (!in[i].empty() || !out[i].empty()) {
      sort(in[i].begin(), in[i].end(), greater<pair<int, int> >());
      if (i > 1)
        for (auto x : in[i]) {
          auto it = v.lower_bound(make_pair(x.second + 1, 0));
          it--;
          if (it->second <= x.second) {
            int s = (sum(x.second) - sum(it->second) + Mod) % Mod;
            add(x.second + 1, s);
            pls.insert(x.second + 1);
          }
        }
      for (auto x : in[i]) {
        auto it = pls.lower_bound(x.first);
        while (it != pls.end() && *it <= x.second) {
          int s = (sum(*it - 1) - sum(*it) + Mod) % Mod;
          add(*it, s);
          pls.erase(it++);
        }
      }
      for (auto x : out[i]) v.erase(x);
      for (auto x : in[i]) v.insert(x);
    }
  printf("%d\n", sum(n));
  return 0;
}
