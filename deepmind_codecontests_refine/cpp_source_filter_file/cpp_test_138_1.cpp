#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 400005;
int n, m, qq;
pair<int, bool> a[N];
pair<int, int> b[N];
int pr[N];
int p[N];
int l[N], r[N];
int q[N];
int first(int x) {
  if (x == p[x]) return x;
  return p[x] = first(p[x]);
}
void kpc(int x, int y) {
  x = first(x);
  y = first(y);
  l[y] = min(l[y], l[x]);
  r[y] = max(r[y], r[x]);
  q[y] += q[x];
  p[x] = y;
}
long long yans[N];
void solv() {
  cin >> n >> m >> qq;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = true;
  }
  for (int i = n + 1; i <= n + m; ++i) {
    cin >> a[i].first;
    a[i].second = false;
  }
  n += m;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= qq; ++i) {
    cin >> b[i].first;
    b[i].second = i;
  }
  vector<pair<int, int> > v;
  for (int i = 1; i < n; ++i) {
    v.push_back(make_pair(a[i + 1].first - a[i].first, i));
  }
  sort((v).begin(), (v).end());
  sort(b + 1, b + qq + 1);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += a[i].first * a[i].second;
  for (int i = 1; i <= n; ++i) pr[i] = pr[i - 1] + a[i].first;
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    l[i] = r[i] = i;
    q[i] = a[i].second;
  }
  int j = 0;
  for (int i = 1; i <= qq; ++i) {
    while (j < ((int)(v).size()) && v[j].first <= b[i].first) {
      int x = v[j].second;
      int y = v[j].second + 1;
      ++j;
      x = first(x);
      y = first(y);
      ans -= (pr[r[x]] - pr[r[x] - q[x]]);
      ans -= (pr[r[y]] - pr[r[y] - q[y]]);
      kpc(x, y);
      x = first(x);
      ans += (pr[r[x]] - pr[r[x] - q[x]]);
    }
    yans[b[i].second] = ans;
  }
  for (int i = 1; i <= qq; ++i) cout << yans[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  while (tt--) {
    solv();
  }
  return 0;
}
