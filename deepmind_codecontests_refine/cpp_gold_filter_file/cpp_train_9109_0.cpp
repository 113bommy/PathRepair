#include <bits/stdc++.h>
using namespace std;
long long sqr(int x) { return x * 1ll * x; }
long long dist(int x, int y, int a, int b) { return sqr(x - a) + sqr(y - b); }
const int N = 2001;
const long long inf = 1e18;
int x[N], y[N], ord[N];
long long p[N], q[N];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  vector<pair<long long, int>> order;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    order.push_back(make_pair(dist(x[i], y[i], x1, y1), i));
  }
  sort(order.begin(), order.end());
  for (int i = 0; i < order.size(); i++) ord[i] = order[i].second;
  long long mn = -inf, ans = inf;
  for (int i = 0; i < n; i++) {
    int idx = ord[i];
    long long D = dist(x[idx], y[idx], x1, y1);
    mn = max(mn, D);
    p[i] = mn;
  }
  mn = -inf;
  for (int i = n - 1; i >= 0; i--) {
    int idx = ord[i];
    long long D = dist(x[idx], y[idx], x2, y2);
    mn = max(mn, D);
    q[i] = mn;
  }
  ans = min(p[n - 1], q[0]);
  for (int i = 0; i < n - 1; i++) {
    ans = min(ans, p[i] + q[i + 1]);
  }
  cout << (long long)ans << endl;
}
