#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 1, inf = 1e18;
vector<pair<long long, long long> > a, b;
vector<pair<pair<long long, long long>, long long> > z;
long long add[4 * N], t[4 * N];
void push(long long v, long long l, long long r) {
  t[v] += add[v];
  if (l != r - 1) {
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
  }
  add[v] = 0;
}
void update(long long v, long long l, long long r, long long vl, long long vr,
            long long val) {
  push(v, l, r);
  if (l >= vr || vl >= r) return;
  if (l >= vl && r <= vr) {
    add[v] += val;
    push(v, l, r);
    return;
  }
  long long m = (l + r) / 2;
  update(2 * v, l, m, vl, vr, val);
  update(2 * v + 1, m, r, vl, vr, val);
  t[v] = max(t[2 * v + 1], t[2 * v]);
}
long long get(long long v, long long l, long long r, long long vl,
              long long vr) {
  push(v, l, r);
  if (l >= vr || vl >= r) return -inf;
  if (l >= vl && r <= vr) {
    return t[v];
  }
  long long m = (l + r) / 2;
  return max(get(2 * v, l, m, vl, vr), get(2 * v + 1, m, r, vl, vr));
}
void fuckyou(long long v, long long l, long long r, long long pos,
             long long val) {
  if (l > pos || r <= pos) return;
  if (l == r - 1) {
    t[v] = max(t[v], val);
    return;
  }
  long long m = (l + r) / 2;
  fuckyou(2 * v, l, m, pos, val);
  fuckyou(2 * v + 1, m, r, pos, val);
  t[v] = max(t[2 * v], t[2 * v + 1]);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < 4 * N; i++) t[i] = -inf;
  long long n, m, p, ans = -inf;
  cin >> n >> m >> p;
  a.resize(n);
  b.resize(m);
  z.resize(p);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
    fuckyou(1, 0, N, b[i].first, -b[i].second);
  }
  for (long long i = 0; i < p; i++) {
    cin >> z[i].first.first >> z[i].first.second >> z[i].second;
  }
  sort((z).begin(), (z).end());
  sort((a).begin(), (a).end());
  cout << endl;
  long long j = 0;
  for (long long i = 0; i < n; i++) {
    while (j < z.size() && a[i].first > z[j].first.first) {
      update(1, 0, N, z[j].first.second + 1, N, z[j].second);
      j++;
    }
    ans = max(ans, -a[i].second + get(1, 0, N, 0, N));
  }
  cout << ans;
}
