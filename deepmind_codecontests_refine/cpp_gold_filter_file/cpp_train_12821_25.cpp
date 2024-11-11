#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
inline int read() {
  int sum = 0, p = 1;
  char ch = getchar();
  while (!(('0' <= ch && ch <= '9') || ch == '-')) ch = getchar();
  if (ch == '-') p = -1, ch = getchar();
  while ('0' <= ch && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
  return sum * p;
}
const int maxn = 1e3 + 20;
int n, p1[maxn], p2[maxn];
int id1[maxn], id2[maxn];
inline void init() {
  n = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++)
    p2[i] = read(), id2[p2[i]] = i;
  for (int i = (1), _end_ = (n); i <= _end_; i++)
    p1[i] = read(), id1[p1[i]] = i;
}
vector<pair<pair<int, int>, pair<int, int> > > ans;
inline void doing() {
  for (int i = (1), _end_ = (n); i <= _end_; i++) {
    int x = id1[i], y = id2[i];
    if (x == i && y == i) continue;
    ans.push_back(make_pair(make_pair(i, x), make_pair(y, i)));
    p1[x] = p1[i];
    p2[y] = p2[i];
    id1[p1[x]] = x;
    id2[p2[y]] = y;
  }
  printf("%d\n", ((int)ans.size()));
  for (pair<pair<int, int>, pair<int, int> > x : ans)
    printf("%d %d %d %d\n", x.first.first, x.first.second, x.second.first,
           x.second.second);
}
int main() {
  init();
  doing();
  return 0;
}
