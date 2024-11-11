#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 100;
long long hinta[MN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<pair<int, int> > v;
  for (int i = 0; i < m; ++i) {
    int q, w;
    cin >> q >> w;
    v.push_back({w, q});
  }
  sort(v.begin(), v.end());
  long long lo = 0;
  long long hi = n;
  long long best = 0;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    long long q = 0;
    if (mid % 2 == 1)
      q = mid * (mid - 1) / 2 + 1;
    else
      q = mid * (mid - 1) / 2 + mid / 2;
    if (q <= n) {
      lo = mid + 1;
      best = max(best, mid);
    } else {
      hi = mid - 1;
    }
  }
  long long ans = 0;
  for (int i = 0; i < min(best, m); ++i) {
    ans += v[v.size() - i - 1].first;
  }
  cout << ans << '\n';
}
