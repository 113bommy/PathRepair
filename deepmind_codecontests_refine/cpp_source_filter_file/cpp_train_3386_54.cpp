#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Line {
  ll k, m;
  Line(ll _k = 0, ll _m = 0) : k(_k), m(_m) {}
  ll operator[](ll x) const { return k + m * x; }
};
long double x_intersect(const Line &l1, const Line &l2) {
  assert(l1.m != l2.m);
  return (long double)(l1.k - l2.k) / (l2.m - l1.m);
}
class ConvexHull {
 private:
  deque<Line> dq;

 public:
  void insert(Line l, bool small = false) {
    while (dq.size() > 1) {
      Line l1, l2;
      if (small) {
        l1 = dq[0];
        l2 = dq[1];
      } else {
        int m = dq.size() - 1;
        l1 = dq[m];
        l2 = dq[m - 1];
      }
      auto x1 = x_intersect(l, l1);
      auto x2 = x_intersect(l, l2);
      if (small)
        if (x1 < x2)
          break;
        else
          dq.pop_front();
      else if (x1 <= x2)
        dq.pop_back();
      else
        break;
    }
    if (small)
      dq.push_front(l);
    else
      dq.push_back(l);
  }
  ll query(ll x) {
    assert(dq.size() >= 1);
    if (dq.size() == 1) return dq[0][x];
    int l = 0, r = dq.size() - 2;
    while (l < r) {
      int m = (l + r) / 2;
      Line l1 = dq[m], l2 = dq[m + 1];
      if (l1[x] < l2[x])
        l = m + 1;
      else
        r = m;
    }
    return max(dq[l][x], dq[l + 1][x]);
  }
};
int main() {
  int n;
  scanf("%i", &n);
  vector<ll> a(n + 1), S(n + 1, 0);
  ll D = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lli", &a[i]);
    S[i] = S[i - 1] + a[i];
    D += i * a[i];
  }
  ConvexHull chtL, chtR;
  ll bestL = 0, bestR = 0, sol = 0;
  do
    ;
  while (0);
  for (int i = 1; i <= n; i++) {
    chtL.insert({-S[i - 1], i}, false);
    bestL = S[i - 1] - i * a[i] + chtL.query(a[i]);
    do
      ;
    while (0);
    sol = max(sol, bestL);
  }
  do
    ;
  while (0);
  do
    ;
  while (0);
  for (int i = n; i > 1; i--) {
    chtR.insert({-S[i], i}, true);
    bestR = S[i] - a[i] * i + chtR.query(a[i]);
    do
      ;
    while (0);
    sol = max(sol, bestR);
  }
  do
    ;
  while (0);
  printf("%lli\n", D + sol);
  return 0;
}
