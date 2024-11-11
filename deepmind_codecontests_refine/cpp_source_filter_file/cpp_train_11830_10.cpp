#include <bits/stdc++.h>
using namespace std;
struct yts {
  int x, id;
  long long t;
  yts(int X, long long T, int ID) {
    x = X;
    t = T;
    id = ID;
  }
  friend bool operator<(yts x, yts y) {
    if (x.x != y.x) return x.x < y.x;
    if (x.t != y.t) return x.t < y.t;
    return x.id < y.id;
  }
};
struct yts1 {
  int x, id;
  long long t;
  yts1(int X, long long T, int ID) {
    x = X;
    t = T;
    id = ID;
  }
  friend bool operator<(yts1 x, yts1 y) { return x.t < y.t; }
};
priority_queue<yts1> q;
set<yts> s;
set<yts>::iterator p, P;
int n, m, k;
long long t;
int a, b;
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    s.insert(yts(x, 0, i));
  }
  while (m--) {
    scanf("%I64d%d%d", &t, &a, &b);
    while (!q.empty()) {
      yts1 x = q.top();
      if (x.t > t) break;
      s.insert(yts(x.x, x.t, x.id));
      q.pop();
    }
    if (s.empty()) {
      long long T = q.top().t;
      while (!q.empty() && q.top().t == T) {
        yts1 x = q.top();
        s.insert(yts(x.x, x.t, x.id));
        q.pop();
      }
    }
    yts ans = yts(0, 0, 0), x = yts(a, 0, 0);
    p = s.lower_bound(x);
    if (p == s.begin())
      ans = *p;
    else if (p == s.end())
      ans = *s.lower_bound(yts((*--p).x, 0, 0));
    else {
      ans = *p;
      P = s.lower_bound(yts((*--p).x, 0, 0));
      if (yts(abs((*P).x - a), (*P).t, (*P).id) <
          yts(abs(ans.x - a), ans.t, ans.id))
        ans = *P;
    }
    printf("%d %I64d\n", ans.id, max(ans.t - t, 0ll) + abs(ans.x - a));
    q.push(yts1(b, max(t, ans.t) + abs(ans.x - a) + abs(a - b), ans.id));
    s.erase(ans);
  }
  return 0;
}
