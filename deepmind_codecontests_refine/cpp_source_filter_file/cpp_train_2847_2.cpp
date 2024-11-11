#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 250000 + 50;
int N, Del[MAX_N];
struct Point {
  long long x, r;
  int y, p;
  void init(long long _x, int _y, int _p, int _r) {
    x = _x;
    y = _y;
    p = _p;
    r = _r;
  }
  bool operator<(const Point &cmp) const { return x < cmp.x; }
} ps[MAX_N];
struct Node {
  Node *lson, *rson;
  set<pair<int, int> > y;
};
Node pool[MAX_N << 2], *curPool, *root;
Node *newNode() {
  curPool->lson = curPool->rson = 0;
  curPool->y.clear();
  return curPool++;
}
int curp;
vector<long long> ptsX;
Node *Build(int segl, int segr) {
  Node *rt = newNode();
  if (segl == segr) {
    for (; curp <= N && ps[curp].x == ptsX[segl]; curp++) {
      rt->y.insert(make_pair(ps[curp].y, curp));
    }
  } else {
    int mid = (segl + segr) >> 1;
    rt->lson = Build(segl, mid);
    rt->rson = Build(mid + 1, segr);
    for (__typeof(rt->lson->y.begin()) it = rt->lson->y.begin();
         it != rt->lson->y.end(); ++it)
      rt->y.insert(*it);
    for (__typeof(rt->rson->y.begin()) it = rt->rson->y.begin();
         it != rt->rson->y.end(); ++it)
      rt->y.insert(*it);
  }
  return rt;
}
void Query(Node *rt, int segl, int segr, long long xl, long long xr, int yr,
           vector<int> &ret) {
  if (xl <= ptsX[segl] && xr >= ptsX[segr]) {
    set<pair<int, int> >::iterator it =
        rt->y.upper_bound(make_pair(yr, 0x3f3f3f3f));
    if (it != rt->y.begin()) {
      set<pair<int, int> >::iterator itL = it;
      while (itL != rt->y.begin()) {
        --itL;
        if (Del[(*itL).second] == 0) {
          ret.push_back((*itL).second);
          Del[(*itL).second] = 1;
        }
      }
      rt->y.erase(rt->y.begin(), it);
    }
    return;
  }
  if (xr < ptsX[segl] || xl > ptsX[segr]) return;
  int mid = (segl + segr) >> 1;
  if (xl <= ptsX[mid]) Query(rt->lson, segl, mid, xl, xr, yr, ret);
  if (xr > ptsX[mid]) Query(rt->rson, mid + 1, segr, xl, xr, yr, ret);
}
int main() {
  int x, y, p, r, x0, y0, m;
  scanf("%d %d %d %d %d", &x0, &y0, &p, &r, &N);
  ps[0].init(0, 0, p, (long long)r * r);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d %d %d %d", &x, &y, &m, &p, &r);
    x -= x0;
    y -= y0;
    ps[i].init((long long)x * x + (long long)y * y, m, p, (long long)r * r);
    ptsX.push_back(ps[i].x);
  }
  sort(ptsX.begin(), ptsX.end());
  ptsX.erase(unique(ptsX.begin(), ptsX.end()), ptsX.end());
  sort(ps + 1, ps + N + 1);
  curPool = pool;
  curp = 1;
  root = Build(0, ptsX.size() - 1);
  queue<int> Q;
  Q.push(0);
  int ret = 0;
  memset(Del, 0, sizeof(Del));
  while (Q.size()) {
    int i = Q.front();
    Q.pop();
    vector<int> rec;
    Query(root, 0, ptsX.size() - 1, 0, ps[i].r, ps[i].p, rec);
    ret += rec.size();
    for (__typeof(rec.begin()) it = rec.begin(); it != rec.end(); ++it)
      Q.push(*it);
  }
  printf("%d\n", ret);
  return 0;
}
