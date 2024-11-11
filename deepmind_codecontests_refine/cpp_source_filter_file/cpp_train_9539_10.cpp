#include <bits/stdc++.h>
using namespace std;
static long long mi[300005][20];
static bool mark[300005][20];
static long long psum[300005];
long long f(int x, int k) {
  if (k == 0) return psum[x];
  if (mark[x][k]) return mi[x][k];
  mark[x][k] = 1;
  return mi[x][k] = min(f(x, k - 1), f(x + (1 << (k - 1)), k - 1));
}
long long qry(int l, int r) {
  int t = r - l + 1;
  int lg = 31 - __builtin_clz(t);
  return min(f(l, lg), f(r - (1 << lg) + 1, lg));
}
int main() {
  long long n, a, b, c, d, start, len;
  scanf("%lld %lld %lld %lld %lld %lld %lld", &n, &a, &b, &c, &d, &start, &len);
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    v.push_back(make_pair(y, x));
  }
  if (v[0].first == 0)
    psum[0] = -d;
  else
    psum[0] = c;
  for (int i = 1; i < n; i++) {
    if (v[i].first)
      psum[i] = psum[i - 1] + c;
    else
      psum[i] = psum[i - 1] - d;
  }
  psum[n] = 1000000000000000000;
  vector<long long> t;
  t.push_back(0);
  for (int i = 0; i < n; i++) {
    t.push_back(v[i].second + 1);
    if (v[i].second - len + 1 >= 0) t.push_back(v[i].second - len + 1);
  }
  sort(t.begin(), t.end());
  int l = 0, r = 0;
  long long at = start;
  for (int i = 0; i < t.size(); i++) {
    while (l < v.size() && v[l].second < t[i]) {
      if (v[l].first)
        at += a;
      else
        at -= b;
      if (at < 0) {
        printf("-1\n");
        return 0;
      }
      l++;
    }
    while (r < v.size() && v[r].second < t[i] + len) r++;
    long long low = qry(l, r) - (l > 0 ? psum[l - 1] : 0) + at;
    if (low >= 0) {
      printf("%lld\n", t[i]);
      return 0;
    }
  }
  return 0;
}
