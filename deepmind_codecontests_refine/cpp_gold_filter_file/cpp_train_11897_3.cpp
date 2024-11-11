#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500;
long long n;
struct node {
  long long x, y, w;
} a[maxn];
struct jgt {
  long long t, d1, d2;
} b[maxn * 10];
struct dian {
  long long x, y, d[4];
} pt[maxn * maxn];
long long bw = 0, cnt, ptw = 0, ANS = 2e11 + 10;
long long c[maxn];
long long fa[maxn];
map<pair<long long, long long>, long long> mp;
bool cmp1(const node &x, const node &y) {
  return x.x == y.x ? x.y < y.y : x.x < y.x;
}
bool cmp2(const node &x, const node &y) {
  return x.y == y.y ? x.x < y.x : x.y < y.y;
}
bool cmp3(const jgt &x, const jgt &y) { return x.t < y.t; }
long long find(long long x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
bool merge(long long x, long long y) {
  long long fx = find(x), fy = find(y);
  if (fx == fy) return 0;
  cnt--;
  fa[fx] = fy;
  return 1;
}
void init1() {
  sort(a + 1, a + n + 1, cmp1);
  for (long long l = 1; l <= n; l++) a[l].w = l;
  for (long long l = 1; l < n; l++) {
    if (a[l].x == a[l + 1].x) {
      b[++bw].t = a[l + 1].y - a[l].y;
      b[bw].d1 = l;
      b[bw].d2 = l + 1;
    }
  }
  sort(a + 1, a + n + 1, cmp2);
  for (long long l = 1; l < n; l++) {
    if (a[l].y == a[l + 1].y) {
      b[++bw].t = a[l + 1].x - a[l].x;
      b[bw].d1 = a[l].w;
      b[bw].d2 = a[l + 1].w;
    }
  }
  sort(a + 1, a + n + 1, cmp1);
}
void update(long long i, long long j) {
  long long x = a[i].x, y = a[j].y, w;
  if (y == a[i].y || x == a[j].x) return;
  if (mp[make_pair(x, y)])
    w = mp[make_pair(x, y)];
  else
    mp[make_pair(x, y)] = w = ++ptw, pt[w].x = x, pt[w].y = y;
  if (x < a[j].x && (a[j].x < a[pt[w].d[0]].x || pt[w].d[0] == 0))
    pt[w].d[0] = j;
  if (x > a[j].x && (a[j].x > a[pt[w].d[1]].x || pt[w].d[1] == 0))
    pt[w].d[1] = j;
  if (y < a[i].y && (a[i].y < a[pt[w].d[2]].y || pt[w].d[2] == 0))
    pt[w].d[2] = i;
  if (y > a[i].y && (a[i].y > a[pt[w].d[3]].y || pt[w].d[3] == 0))
    pt[w].d[3] = i;
}
void init2() {
  for (long long i = 1; i < n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      update(i, j);
      update(j, i);
    }
  }
}
long long gett(long long x1, long long y1, long long i) {
  return max(abs(x1 - a[i].x), abs(y1 - a[i].y));
}
int main() {
  cin >> n;
  cnt = n;
  for (long long l = 1; l <= n; l++) {
    cin >> a[l].x >> a[l].y;
    fa[l] = l;
  }
  init1();
  init2();
  sort(b + 1, b + bw + 1, cmp3);
  for (int l = 0; l <= bw; l++) {
    if ((l == 0 || merge(b[l].d1, b[l].d2)) && cnt <= 4) {
      if (cnt == 1) {
        ANS = min(ANS, b[l].t);
      }
      memset(c, 0, sizeof(c));
      for (long long i = 1, wy = 1; i <= n; i++) {
        find(i);
        if (c[fa[i]] == 0) c[fa[i]] = wy++;
        c[i] = c[fa[i]];
      }
      for (long long j = 1; j <= ptw; j++) {
        long long p[5] = {(long long)(2e11 + 10), (long long)(2e11 + 10),
                          (long long)(2e11 + 10), (long long)(2e11 + 10),
                          (long long)(2e11 + 10)},
                  x = pt[j].x, y = pt[j].y;
        for (long long k = 0; k <= 3; k++) {
          if (pt[j].d[k] != 0)
            p[c[pt[j].d[k]]] = min(p[c[pt[j].d[k]]], gett(x, y, pt[j].d[k]));
        }
        long long ans = b[l].t;
        for (long long k = 1; k <= cnt; k++) {
          ans = max(ans, p[k]);
        }
        ANS = min(ANS, ans);
      }
      if (cnt == 2) {
        for (long long j = l + 1; j <= bw; j++) {
          if (find(b[j].d1) != find(b[j].d2)) {
            ANS = min(ANS, max(b[l].t, (long long)(ceil(b[j].t / 2.0))));
            break;
          }
        }
      }
    }
  }
  if (ANS >= 2e10 + 1)
    cout << -1 << endl;
  else
    cout << ANS << endl;
}
