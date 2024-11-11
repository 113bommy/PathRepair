#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T &x) {
  char ch = getchar();
  int f = 1;
  x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x), read(args...);
}
int n, r[1050], c[1050];
vector<pair<pair<int, int>, pair<int, int> > > ans;
int main() {
  read(n);
  for (register int i = 1; i <= n; ++i) read(r[i]);
  for (register int i = 1; i <= n; ++i) read(c[i]);
  for (register int i = n; i >= 1; --i) {
    if (r[i] == i && c[i] == i) continue;
    for (register int j = 1; j <= i - 1; ++j)
      if (r[j] == i) r[j] = r[i];
    for (register int j = 1; j <= i - 1; ++j)
      if (c[j] == i) c[j] = c[i];
    ans.push_back(make_pair(make_pair(r[i], i), make_pair(i, c[i])));
  }
  cout << ans.size() << endl;
  for (auto v : ans)
    cout << v.first.first << ' ' << v.first.second << ' ' << v.second.first
         << ' ' << v.second.second << endl;
  return 0;
}
