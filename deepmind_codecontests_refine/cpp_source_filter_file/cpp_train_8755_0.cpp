#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7, MOD = 1e9 + 7;
vector<pair<long long, long long>> seg;
long long calc[MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  long long sol = 0;
  for (int i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    seg.emplace_back(make_pair(l, r));
  }
  sort(seg.begin(), seg.end());
  int j = 0;
  for (auto it : seg) calc[j++] = x + 1ll * y * (it.second - it.first);
  set<long long> s;
  for (int i = 0; i < n; i++) {
    long long tmp = seg[i].first;
    auto lb = s.lower_bound(tmp);
    if (lb != s.begin()) {
      lb--;
      long long lob = *lb;
      if (1ll * (seg[i].second - lob) * y < calc[i])
        s.erase(lob), sol = (sol + 1ll * y * (seg[i].second - lob)) % MOD;
      else
        sol = (sol + calc[i]) % MOD;
    } else
      sol = (sol + calc[i]) % MOD;
    s.insert(seg[i].second);
  }
  cout << sol << '\n';
  return 0;
}
