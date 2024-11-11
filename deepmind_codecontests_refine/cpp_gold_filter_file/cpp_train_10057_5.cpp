#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n, k, sol = 1;
  cin >> n >> k;
  vector<long long> p(n), ln(n + 1, 0), lp(n), e;
  for (long long &i : p) cin >> i;
  sort(p.begin(), p.end());
  for (long long f = 0, a = 1, mn = 0, i; f < n; a += mn) {
    e.push_back(a);
    for (i = f; i < n; ++i) {
      lp[i] = p[i] / a * a;
      ln[i] = p[i] / a - 1;
    }
    while (ln[f] < 0) ++f;
    for (i = f, mn = 1LL << 60; i < n; ++i)
      mn = min(mn, (p[i] - lp[i]) / (ln[i] + 1) + 1);
  }
  function<long long(long long)> eval = [&](long long d) {
    long long c = 0;
    for (long long i : p) c += (i + d - 1) / d * d - i;
    return c;
  };
  e.push_back(p.back() + k + 2);
  for (long long i = e.size() - 2, bgn, end, md; i > 0; --i) {
    bgn = e[i], end = e[i] < e[i + 1] - 2 ? e[i + 1] - 2 : e[i];
    while (bgn < end) {
      md = (bgn + end + 1) >> 1LL;
      if (eval(md) <= k)
        bgn = md;
      else
        end = md - 1;
    }
    if (eval(bgn) <= k) {
      sol = bgn;
      break;
    }
    if (eval(e[i] - 1) <= k) {
      sol = e[i] - 1;
      break;
    }
  }
  cout << sol << "\n";
  return 0;
}
