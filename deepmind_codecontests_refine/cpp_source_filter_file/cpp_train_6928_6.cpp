#include <bits/stdc++.h>
using namespace std;
map<int, int> Convex[2];
inline long long Cross(int x1, int y1, int x2, int y2) {
  return 1LL * x1 * y2 - 1LL * x2 * y1;
}
bool Check(map<int, int>& cov, int x, int y) {
  if (cov.size() == 0) return false;
  if (cov.find(x) != cov.end()) return y >= cov[x];
  if (x < cov.begin()->first || x > (--cov.end())->first) return false;
  map<int, int>::iterator p = cov.lower_bound(x), q = p;
  --q;
  return Cross(q->first - x, q->second - y, p->first - x, p->second - y) >= 0;
}
void Insert(map<int, int>& cov, int x, int y) {
  if (Check(cov, x, y)) return;
  cov[x] = y;
  map<int, int>::iterator p = cov.upper_bound(x), q;
  while (p != cov.end()) {
    q = p;
    ++q;
    if (q == cov.end() || Cross(p->first - x, p->second - y,
                                q->first - p->first, q->second - p->second) < 0)
      break;
    cov.erase(p);
    p = q;
  }
  p = cov.find(x);
  if (p == cov.begin() || --p == cov.begin()) return;
  while (p != cov.begin()) {
    q = p;
    --q;
    if (Cross(p->first - q->first, p->second - q->second, x - p->first,
              y - p->second) > 0)
      break;
    cov.erase(p);
    p = q;
  }
}
int main(int argc, char* argv[]) {
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int tp, x, y;
    scanf("%d%d%d", &tp, &x, &y);
    if (tp == 1) {
      Insert(Convex[0], x, y);
      Insert(Convex[1], x, -y);
    } else {
      int ret = Check(Convex[0], x, y) && Check(Convex[1], x, -y);
      if (ret)
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
