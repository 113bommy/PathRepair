#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10, N = 2e5 + 10, B = 1e9 + 7;
int n, q;
vector<int> d[M];
int a[N];
long long gg[M], ff[M];
vector<pair<pair<int, int>, int> > v;
vector<int> ps[M];
long long ans[N];
long long u[N];
long long mypw(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % B;
    a = a * a % B;
    b >>= 1;
  }
  return ret;
}
long long inv(long long x) { return mypw(x, B - 2); }
void init() {
  for (int i = 2; i < M; ++i)
    if (d[i].empty()) {
      ff[i] = (i - 1) * inv(i) % B;
      gg[i] = inv(ff[i]);
      for (int j = i; j < M; j += i) d[j].push_back(i);
    }
}
void modify(int x, long long v) {
  for (; x <= n; x += x & -x) {
    u[x] = u[x] * v % B;
  }
}
long long query(int x) {
  long long s = 1;
  for (; x; x -= x & -x) {
    s = s * u[x] % B;
  }
  return s;
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = n; i >= 1; --i) {
    for (int j : d[a[i]]) {
      ps[j].push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    u[i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    modify(i, a[i]);
  }
  for (int i = 1; i < M; ++i) {
    if (ps[i].empty()) continue;
    int x = ps[i].back();
    modify(x, ff[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    v.push_back(make_pair(make_pair(l, r), i));
  }
  sort(v.begin(), v.end());
  int j = 1;
  for (int i = 0; i < v.size(); ++i) {
    int l = v[i].first.first;
    int r = v[i].first.second;
    int ii = v[i].second;
    for (; j < l; ++j) {
      modify(j, inv(a[j]));
      for (int k : d[a[j]]) {
        assert(ps[k].back() == j);
        modify(j, gg[k]);
        ps[k].pop_back();
        if (!ps[k].empty()) modify(ps[k].back(), ff[k]);
      }
    }
    ans[ii] = query(r);
  }
  for (int i = 0; i < q; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
