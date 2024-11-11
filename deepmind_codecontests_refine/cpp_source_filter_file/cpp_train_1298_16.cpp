#include <bits/stdc++.h>
using namespace std;
struct sb {
  long long h, a;
  double t, h1;
  bool operator<(const sb &x) const { return t > x.t; }
} s[100500], tmp;
priority_queue<sb> q;
int i, j, k, n, m, p, tme;
long long l, r, mid, res;
bool yes;
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  for (i = 1; i <= n; i++) {
    scanf("%lld%lld", &s[i].h, &s[i].a);
  }
  l = 0;
  r = 1e15;
  while (l <= r) {
    mid = (l + r) / 2;
    tme = 0;
    yes = 1;
    priority_queue<sb> clr;
    swap(q, clr);
    for (i = 1; i <= n; i++) {
      s[i].h1 = mid;
      if (s[i].a == 0) {
        s[i].t = 114514;
      } else {
        s[i].t = s[i].h1 / s[i].a;
      }
      if (s[i].h1 - s[i].a * m < s[i].h - 0.00000001) {
        q.push(s[i]);
      }
    }
    for (i = 1; i <= m; i++) {
      if (q.empty()) {
        goto aaa;
      }
      tme++;
      if (q.top().t < tme - 0.0000000001) {
        yes = 0;
        goto aaa;
      }
      for (j = 1; j <= k; j++) {
        if (q.empty()) {
          goto aaa;
        }
        tmp = q.top();
        q.pop();
        tmp.h1 += p;
        if (tmp.a != 0) {
          tmp.t = tmp.h1 / tmp.a;
        }
        if (tmp.h1 - tmp.a * m > tmp.h - 0.00000001) {
        } else {
          q.push(tmp);
        }
      }
    }
  aaa:
    if (yes && q.empty()) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%lld", mid);
}
