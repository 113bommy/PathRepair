#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const double PI = acos(-1.0);
using namespace std;
const double EPS = 1e-9;
const int N = 5e5 + 9;
long long n, m, a[N], b[N];
bool ok(long long t) {
  queue<long long> q;
  for (int i = 1; i <= m; i++) q.push(b[i]);
  for (int i = 1; i <= n; i++) {
    if (abs(a[i] - q.front()) > t) continue;
    long long l, r;
    if (q.front() < a[i]) {
      l = q.front();
      long long x = t - (a[i] - q.front());
      if (x / 2 < a[i] - q.front())
        r = a[i] + x / 2LL;
      else
        r = a[i] + t - (a[i] - q.front()) * 2;
    } else {
      l = a[i];
      r = a[i] + t;
    }
    while (!q.empty() && q.front() <= r) q.pop();
    if (q.empty()) return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  long long l = 0, r = 1e18, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}
