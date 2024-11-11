#include <bits/stdc++.h>
using namespace std;
struct eq {
  long long m, c;
  eq(long long _m, long long _c) : m(_m), c(_c) {}
};
long long arr[2000005], p[2000005];
vector<eq> ch;
bool keep(eq a, eq b, eq c) {
  double x1 = 1.0 * (a.c - c.c) / (c.m - a.m);
  double x2 = 1.0 * (a.c - b.c) / (b.m - a.m);
  return x2 < x1;
}
void add(eq nw) {
  while (ch.size() > 1 && !keep(ch[ch.size() - 2], ch.back(), nw))
    ch.pop_back();
  ch.push_back(nw);
}
long long f(long long i, long long x) { return ch[i].m * x + ch[i].c; }
long long ternary_search(long long x, long long l = 0,
                         long long r = ch.size() - 1) {
  long long lo = l, hi = r;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (f(mid, x) >= f(mid + 1, x)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return f(lo, x);
}
void solve() {
  long long i, n, j, m, k, l, x, y, ret = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
    p[i] = p[i - 1] + arr[i];
  }
  add({0, 0});
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    ans = max(ans, (ternary_search(arr[i]) + p[i] - i * arr[i]));
    x = i;
    y = -p[i];
    add({x, y});
  }
  ch.clear();
  add({-n, -p[n]});
  for (i = n - 1; i >= 0; i--) {
    ans = max(ans, (ternary_search(-arr[i]) + p[i] - i * arr[i]));
    x = -i;
    y = -p[i];
    add({x, y});
  }
  for (i = 1; i <= n; i++) ans += i * arr[i];
  cout << ans << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  t = 1;
  while (t--) solve();
  return 0;
}
