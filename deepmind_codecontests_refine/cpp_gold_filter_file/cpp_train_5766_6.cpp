#include <bits/stdc++.h>
using namespace std;
int n, m, K, x[100010], y[100010];
set<int> pt[100010], p[2][200010];
inline int getid(int x, int y, int typ) { return typ ? x - y + 100002 : x + y; }
void insert(int x, int y) {
  pt[x].insert(y);
  p[0][getid(x, y, 0)].insert(x);
  p[1][getid(x, y, 1)].insert(x);
}
class node {
 public:
  pair<int, int> p;
  long long len;
  int d;
  inline node add(long long v) { return (node){p, len + v, d}; }
};
const pair<int, int> dir[4] = {make_pair(-1, 1), make_pair(-1, -1),
                               make_pair(1, -1), make_pair(1, 1)};
pair<int, int> operator+(const pair<int, int> A, const pair<int, int> B) {
  return make_pair(A.first + B.first, A.second + B.second);
}
inline int getnxt(const set<int> &A, int b) { return *A.lower_bound(b); }
inline int getpre(const set<int> &A, int b) {
  auto it = A.lower_bound(b);
  it--;
  return *it;
}
inline bool chk(int x, int y) { return pt[x].find(y) != pt[x].end(); }
pair<int, int> st;
node dfs(pair<int, int> pos, int d, bool f = 0) {
  int pp = getid(pos.first, pos.second, d % 2);
  set<int> &t = p[d % 2][pp];
  if (f)
    st = pos;
  else {
    if (getid(pos.first, pos.second, d % 2) ==
        getid(st.first, st.second, d % 2)) {
      if (d < 2) {
        if (getpre(t, pos.first) < st.first)
          return (node){st, pos.first - st.first, -1};
      } else {
        if (getnxt(t, pos.first) > st.first)
          return (node){st, st.first - pos.first, -1};
      }
    }
  }
  int nxtx, nxty, c1, c2;
  switch (d) {
    case 0:
      nxtx = getpre(t, pos.first);
      nxty = pp - nxtx;
      c1 = chk(nxtx, nxty - 1), c2 = chk(nxtx + 1, nxty);
      if (!(c1 ^ c2))
        return (node){make_pair(nxtx + 1, nxty - 1), pos.first - nxtx, 2};
      if (c1) {
        node ret = dfs(make_pair(nxtx + 1, nxty), 3);
        return ret.add(pos.first - nxtx);
      } else {
        node ret = dfs(make_pair(nxtx, nxty - 1), 1);
        return ret.add(pos.first - nxtx);
      }
      break;
    case 1:
      nxtx = getpre(t, pos.first);
      nxty = nxtx + pos.second - pos.first;
      c1 = chk(nxtx, nxty + 1), c2 = chk(nxtx + 1, nxty);
      if (!(c1 ^ c2))
        return (node){make_pair(nxtx + 1, nxty + 1), pos.first - nxtx, 3};
      if (c1) {
        node ret = dfs(make_pair(nxtx + 1, nxty), 2);
        return ret.add(pos.first - nxtx);
      } else {
        node ret = dfs(make_pair(nxtx, nxty + 1), 0);
        return ret.add(pos.first - nxtx);
      }
      break;
    case 2:
      nxtx = getnxt(t, pos.first);
      nxty = pp - nxtx;
      c1 = chk(nxtx, nxty + 1), c2 = chk(nxtx - 1, nxty);
      if (!(c1 ^ c2))
        return (node){make_pair(nxtx - 1, nxty + 1), nxtx - pos.first, 0};
      if (c1) {
        node ret = dfs(make_pair(nxtx - 1, nxty), 1);
        return ret.add(nxtx - pos.first);
      } else {
        node ret = dfs(make_pair(nxtx, nxty + 1), 3);
        return ret.add(nxtx - pos.first);
      }
      break;
    default:
      nxtx = getnxt(t, pos.first);
      nxty = nxtx + pos.second - pos.first;
      c1 = chk(nxtx, nxty - 1), c2 = chk(nxtx - 1, nxty);
      if (!(c1 ^ c2))
        return (node){make_pair(nxtx - 1, nxty - 1), nxtx - pos.first, 1};
      if (c1) {
        node ret = dfs(make_pair(nxtx - 1, nxty), 0);
        return ret.add(nxtx - pos.first);
      } else {
        node ret = dfs(make_pair(nxtx, nxty - 1), 2);
        return ret.add(nxtx - pos.first);
      }
      break;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= K; i++) {
    scanf("%d%d", &x[i], &y[i]);
    insert(x[i], y[i]);
  }
  for (int i = 0; i <= n + 1; i++) insert(i, 0), insert(i, m + 1);
  for (int i = 0; i <= m + 1; i++) insert(0, i), insert(n + 1, i);
  int sx, sy;
  scanf("%d%d", &sx, &sy);
  string d;
  cin >> d;
  int sd = -1;
  if (d == "NE")
    sd = 0;
  else if (d == "NW")
    sd = 1;
  else if (d == "SE")
    sd = 3;
  else
    sd = 2;
  node c = dfs(make_pair(sx, sy), sd, 1);
  if (c.d != -1) c = dfs(c.p, c.d, 1);
  printf("%lld\n", c.len);
  return 0;
}
