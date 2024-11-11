#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
long long n, a, d[MAXN], v[MAXN], P[MAXN];
vector<pair<int, long long> > vc;
long long ans;
int main() {
  cin >> n >> a;
  vc.push_back({0, 0});
  P[0] = -1e9;
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> v[i];
    ans = max(ans, a - v[i]);
    v[i] -= a;
    if (i == 0) continue;
    v[i] += v[i - 1];
    long long mn;
    if (i >= 2)
      mn = v[i - 2];
    else
      mn = 0;
    while (!vc.empty() && vc.back().first <= d[i] - d[i - 1])
      mn = max(mn, vc.back().second), vc.pop_back();
    vc.push_back({d[i] - d[i - 1], mn});
    mn -= (d[i] - d[i - 1]) * (d[i] - d[i - 1]);
    P[vc.size()] = max(P[vc.size() - 1], mn);
    ans = max(ans, -v[i] + P[vc.size()]);
  }
  cout << ans;
}
