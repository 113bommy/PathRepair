#include <bits/stdc++.h>
using namespace std;
struct island {
  long long l, r;
} I[200005];
struct range {
  long long l, r;
  int i;
  bool operator<(const range &o) const { return l < o.l; }
};
struct point {
  long long v;
  int i;
  bool operator<(const point &o) const { return v < o.v; }
};
struct setrange {
  long long e;
  int i;
  bool operator<(const setrange &o) const { return e < o.e; }
};
int N, M, rind, ans[200005];
long long a[200005];
vector<range> r;
vector<point> p;
set<setrange> s;
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < (N); i++) scanf("%lld %lld", &I[i].l, &I[i].r);
  for (int i = 0; i < (N - 1); i++) {
    r.push_back({I[i + 1].l - I[i].r, I[i + 1].r - I[i].l, i});
    ans[i] = -1;
  }
  for (int i = 0; i < (M); i++) {
    scanf("%lld", &a[i]);
    p.push_back({a[i], i});
  }
  sort(r.begin(), r.end());
  sort(p.begin(), p.end());
  for (point P : p) {
    while (rind < (int)r.size() && r[rind].l <= P.v) {
      s.insert({r[rind].r, r[rind].i}), rind++;
    }
    while (s.size() && s.begin()->e < P.v) s.erase(s.begin());
    if (s.size()) {
      ans[s.begin()->i] = P.i;
      s.erase(s.begin());
    }
  }
  for (int i = 0; i < (N - 1); i++) {
    if (ans[i] == -1) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int i = 0; i < (N - 1); i++) {
    printf("%d ", 1 + ans[i]);
  }
  return 0;
}
