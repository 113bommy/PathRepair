#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 228;
ll t;
ll sum[2][N];
vector<ll> b;
int n, m;
ll md(ll x) { return x < 0 ? -x : x; }
set<ll> s1, s2;
ll get_ans() {
  ll res = 2e18;
  if (!s1.empty()) {
    res = min({res, md(t - *s1.begin()), md(t - *s1.rbegin())});
  }
  if (!s2.empty()) {
    res = min({res, md(t + *s2.begin()), md(t + *s2.rbegin())});
  }
  if (t < 0) {
    auto it = s2.lower_bound(-t);
    if (it != s2.end()) res = min(res, md(t + *it));
    if (it != s2.begin()) res = min(res, md(t + *--it));
  } else {
    auto it = s1.lower_bound(t);
    if (it != s1.end()) res = min(res, md(t + -*it));
    if (it != s1.begin()) res = min(res, md(t - *--it));
  }
  return res;
}
int main() {
  int q;
  scanf("%d%d%d", &n, &m, &q);
  int qwe = 1;
  for (int i = 0; i < n; ++i) {
    ll x;
    scanf("%lld", &x);
    t += x * qwe;
    qwe = -qwe;
  }
  qwe = -1;
  for (int i = 0; i < m; ++i) {
    ll x;
    scanf("%lld", &x);
    sum[0][i] = x * qwe;
    qwe = -qwe;
    sum[1][i] = x * qwe;
    if (i > 0) {
      sum[0][i] += sum[0][i - 1];
      sum[1][i] += sum[1][i - 1];
    }
  }
  b.resize(m - n + 1);
  for (int i = n - 1, step = 0; step <= m - n; ++step, ++i) {
    b[step] = sum[step % 2][i];
    if (step > 0) b[step] -= sum[step % 2][step - 1];
    if (b[step] < 0)
      s1.insert(-b[step]);
    else
      s2.insert(b[step]);
  }
  sort(b.begin(), b.end());
  printf("%lld\n", get_ans());
  while (q--) {
    int l, r;
    ll x;
    scanf("%d%d", &l, &r);
    scanf("%lld", &x);
    int len = r - l + 1;
    if (len & 1) {
      if (l & 1)
        t += x;
      else
        t -= x;
    }
    printf("%lld\n", get_ans());
  }
}
