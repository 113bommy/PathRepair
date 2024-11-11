#include <bits/stdc++.h>
long long bigmod(long long a, long long b) {
  if (b == 0) return 1;
  long long ret = bigmod(a, b / 2);
  return ret * ret % 1000000007 * (b % 2 ? a : 1) % 1000000007;
}
using namespace std;
double a, b, c, d;
int k;
long long tap(long long x, long long y, long long x2, long long y2) {
  if (y2 < x || x2 > y) return 0;
  return min(y, y2) - max(x, x2) + 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> c >> d >> k;
  vector<long long> L, last;
  L.push_back(0);
  last.push_back(0);
  for (int i = 1; i <= 10; i++) {
    vector<long long> cur;
    for (auto h : last) cur.push_back(h * 10 + 4);
    for (auto h : last) cur.push_back(h * 10 + 7);
    for (auto h : cur) L.push_back(h);
    swap(last, cur);
  }
  sort(L.begin(), L.end());
  L.push_back(2e15);
  double ans = 0;
  for (long long i = k; i < L.size() - 1; i++) {
    long long l = L[i - k] + 1, r = L[i - k + 1];
    long long l1 = L[i], r1 = L[i + 1] - 1;
    if (k == 1 && b >= L[i] && c <= L[i]) ans--;
    ans += tap(l, r, a, b) * tap(l1, r1, c, d) +
           tap(l, r, c, d) * tap(l1, r1, a, b);
  }
  ans /= (b - a + 1) * (d - c + 1);
  printf("%.12lf", ans);
}
