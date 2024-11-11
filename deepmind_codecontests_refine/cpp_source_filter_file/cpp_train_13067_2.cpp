#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long d, n, m;
  cin >> d >> n >> m;
  vector<pair<long long, long long>> e(m);
  for (auto &i : e) cin >> i.first >> i.second;
  e.push_back({d, 0});
  sort(e.begin(), e.end());
  deque<pair<long long, long long>> q;
  q.push_back({n, 0});
  long long l = 0, ans = 0;
  for (auto &i : e) {
    long long x, p;
    tie(x, p) = i;
    long long s = n;
    long long t = x - l;
    while (t > 0) {
      if (q.empty()) {
        cout << "-1\n";
        return 0;
      }
      long long f, pf;
      tie(f, pf) = q.front();
      q.pop_front();
      long long k = min(f, t);
      t -= k;
      f -= k;
      s -= k;
      ans += k * pf;
      if (f > 0) q.push_back({f, pf});
    }
    while (!q.empty() && q.back().second >= p) {
      s -= q.back().first;
      q.pop_back();
    }
    q.push_back({n - s, p});
    l = x;
  }
  cout << ans << "\n";
  return 0;
}
