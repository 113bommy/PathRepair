#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100010;
const long long INF = 1000000000000000000LL;
int n, m;
struct node {
  long long t;
  int x, y, p, u;
  bool operator<(const node &A) const { return t < A.t; }
} p[MaxN];
long long ans[MaxN];
void init() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d%d%d", &p[i].t, &p[i].x, &p[i].y);
    p[i].p = i;
  }
  sort(p + 1, p + n + 1);
}
set<pair<int, int> > U, D;
void work() {
  int nowx = 1;
  long long nowt = 0;
  p[n + 1].t = INF;
  for (int i = 1; i <= n + 1; ++i) {
    if (p[i].t == p[i - 1].t) continue;
    while (1) {
      if (U.empty() && D.empty()) break;
      if (U.size() >= D.size()) {
        set<pair<int, int> >::iterator it = U.begin();
        if (it->first - nowx > p[i].t - nowt) {
          nowx += p[i].t - nowt;
          nowt = p[i].t;
          break;
        }
        nowt += it->first - nowx;
        nowx = it->first;
        while (1) {
          if (U.empty()) break;
          it = U.begin();
          if (it->first != nowx) break;
          if (!p[it->second].u) {
            if (p[it->second].y > nowx)
              U.insert(pair<int, int>(p[it->second].y, it->second));
            else
              D.insert(pair<int, int>(p[it->second].y, it->second));
            p[it->second].u = 1;
          } else
            ans[p[it->second].p] = nowt;
          U.erase(it);
        }
      } else {
        set<pair<int, int> >::iterator it = --D.end();
        if (nowx - it->first > p[i].t - nowt) {
          nowx += p[i].t - nowt;
          nowt = p[i].t;
          break;
        }
        nowt += nowx - it->first;
        nowx = it->first;
        while (1) {
          if (D.empty()) break;
          it = --D.end();
          if (it->first != nowx) break;
          if (!p[it->second].u) {
            if (p[it->second].y > nowx)
              U.insert(pair<int, int>(p[it->second].y, it->second));
            else
              D.insert(pair<int, int>(p[it->second].y, it->second));
            p[it->second].u = 1;
          } else
            ans[p[it->second].p] = nowt;
          D.erase(it);
        }
      }
    }
    if (i == n + 1) break;
    nowt = p[i].t;
    for (int j = i; j <= n; ++j) {
      if (p[j].t != nowt) break;
      if (p[j].x == nowx) {
        p[j].u = 1;
        if (p[j].y > nowx)
          U.insert(pair<int, int>(p[j].y, j));
        else
          D.insert(pair<int, int>(p[j].y, j));
      } else if (p[j].x > nowx)
        U.insert(pair<int, int>(p[j].x, j));
      else
        D.insert(pair<int, int>(p[j].x, j));
    }
  }
  for (int i = 1; i <= n; ++i) printf("%I64d\n", ans[i]);
}
int main() {
  init();
  work();
  return 0;
}
