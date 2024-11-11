#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  char c = getchar();
  int flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
template <class T>
inline T _max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T _min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline bool checkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
inline bool checkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int N = 2000005;
int n, a[N], b[N];
void init() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i) read(b[i]);
}
void solve() {
  vector<pair<pair<int, int>, pair<int, int> > > ans;
  for (int rnd = 1; rnd < n; ++rnd) {
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == rnd) x = i;
    }
    for (int i = 1; i <= n; ++i) {
      if (b[i] == rnd) y = i;
    }
    if (!x || !y) {
      printf("-1\n");
      return;
    }
    if (!(x == y && x == rnd)) {
      ans.push_back(make_pair(make_pair(rnd, y), make_pair(x, rnd)));
      a[x] = a[rnd], b[y] = b[rnd];
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second,
           ans[i].second.first, ans[i].second.second);
  }
}
int main() {
  init();
  solve();
  return 0;
}
