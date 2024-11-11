#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int SINF = 1 << 30;
const int N = 100003;
int bt[N];
void update(int x, int c) {
  for (; x < N; x += (x & (-x))) bt[x] += c;
}
int query(int x) {
  int res = 0;
  for (; x > 0; x -= (x & (-x))) res += bt[x];
  return res;
}
struct Person {
  int t, s, f, i;
};
inline bool operator<(const Person& a, const Person& b) { return a.t < b.t; }
Person p[N];
long long res[N];
int x = 1, dir = 0;
long long t = 0, nt = INF;
int k = 0;
set<pair<int, int> > s;
void move(long long ct) {
  x += dir * ct;
  t += ct;
  if (!s.empty()) {
    int a = query(x);
    dir = ((int)s.size() - a >= a ? 1 : -1);
    if (dir == 1)
      nt = t + s.lower_bound(pair<int, int>(x, -SINF))->first - x;
    else
      nt = t + x - (--s.lower_bound(pair<int, int>(x, -SINF)))->first;
  } else {
    dir = 0;
    nt = INF;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &p[i].t, &p[i].s, &p[i].f);
    p[i].i = i;
  }
  sort(p, p + n);
  while (true) {
    if (s.empty() && k == n) break;
    if (k == n || nt <= p[k].t) {
      if (dir == 1) {
        set<pair<int, int> >::iterator it =
            s.lower_bound(pair<int, int>(x, -SINF));
        int y = it->first;
        while (it != s.end() && it->first == y) {
          if (it->second > 0) {
            int i = it->second - 1;
            update(p[i].f, 1);
            s.insert(pair<int, int>(p[i].f, -i));
          } else
            res[p[-it->second].i] = nt;
          update(it->first, -1);
          s.erase(it++);
        }
      } else {
        set<pair<int, int> >::iterator it =
            --s.lower_bound(pair<int, int>(x, -SINF));
        int y = it->first;
        while (it->first == y) {
          if (it->second > 0) {
            int i = it->second - 1;
            update(p[i].f, 1);
            s.insert(pair<int, int>(p[i].f, -i));
          } else
            res[p[-it->second].i] = nt;
          update(it->first, -1);
          if (it == s.begin()) {
            s.erase(it);
            break;
          }
          s.erase(it--);
        }
      }
      move(nt - t);
    } else {
      if (p[k].s == x + dir * (p[k].t - t)) {
        update(p[k].f, 1);
        s.insert(pair<int, int>(p[k].f, -k));
      } else {
        update(p[k].s, 1);
        s.insert(pair<int, int>(p[k].s, k + 1));
      }
      move(p[k].t - t);
      ++k;
    }
  }
  for (int i = 0; i < n; ++i) printf("%lld\n", res[i]);
  return 0;
}
