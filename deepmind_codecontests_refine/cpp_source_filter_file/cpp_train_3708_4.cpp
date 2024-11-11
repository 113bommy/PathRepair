#include <bits/stdc++.h>
using namespace std;
const long long $inf = (long long)2e18;
const int maxn = 100 * 1000;
const int ts = 1 << 17;
int n;
long long a[maxn], dp[maxn + 1];
pair<long long, int> p[2 * ts], q[2 * ts], r[2 * ts];
void build_tree(pair<long long, int> *st) {
  for (int i = ts - 1; i; i--) st[i] = max(st[2 * i], st[2 * i + 1]);
}
pair<long long, int> $max(pair<long long, int> *st, int l, int r, int L = 1,
                          int R = ts, int v = 1) {
  if (l <= L && R <= r) return st[v];
  if (l > R || L > r) return {-$inf, 0};
  return max($max(st, l, r, L, (L + R) / 2, 2 * v),
             $max(st, l, r, (L + R) / 2 + 1, R, 2 * v + 1));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> p[0].first >> q[0].first >> r[0].first;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[ts + i].first = p[0].first * a[i];
    q[ts + i].first = q[0].first * a[i];
    r[ts + i].first = r[0].first * a[i];
    p[ts + i].second = q[ts + i].second = r[ts + i].second = i + 1;
  }
  build_tree(p);
  build_tree(q);
  build_tree(r);
  dp[0] = -$inf;
  for (int i = 1; i <= n; i++) {
    long long t = -$inf;
    pair<long long, int> temp1, temp2, temp3;
    temp1 = $max(p, 1, i);
    temp2 = $max(q, temp1.second, i);
    temp3 = $max(r, temp2.second, i);
    t = temp1.first + temp2.first + temp3.first;
    temp3 = $max(r, temp1.second, i);
    temp2 = $max(q, temp1.second, temp3.second);
    t = max(t, temp1.first + temp3.first + temp2.first);
    temp2 = $max(q, 1, i);
    temp1 = $max(p, 1, temp2.second);
    temp3 = $max(r, temp2.second, i);
    t = max(t, temp1.first + temp3.first + temp2.first);
    temp3 = $max(r, 1, i);
    temp1 = $max(p, 1, temp3.second);
    temp2 = $max(q, temp1.second, temp3.second);
    t = max(t, temp1.first + temp3.first + temp2.first);
    temp2 = $max(q, 1, temp3.second);
    temp1 = $max(p, 1, temp2.second);
    t = max(t, temp1.first + temp3.first + temp2.first);
    dp[i] = max(dp[i - 1], t);
  }
  cout << dp[n];
  return 0;
}
