#include <bits/stdc++.h>
using namespace std;
map<long long, long long> vis;
vector<long long> vc;
int main() {
  long long n, m, tp, sum;
  scanf("%lld %lld", &n, &m);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &tp);
    vis[tp]++;
    vc.push_back(tp);
  }
  sort(vc.begin(), vc.end());
  vc.erase(unique(vc.begin(), vc.end()), vc.end());
  long long l = 0, r = vc.size() - 1, mins = vc[0], maxs = vc[r];
  while (m && l < r) {
    if (vis[vc[l]] <= vis[vc[r]]) {
      sum = (vc[l + 1] - vc[l]) * vis[vc[l]];
      if (m >= sum) {
        m -= sum;
        vis[vc[l + 1]] += vis[vc[l]];
        l++;
        mins = vc[l];
      } else {
        long long x = m / vis[vc[l]];
        m = 0;
        mins = vc[l] + x;
      }
    } else {
      sum = (vc[r] - vc[r - 1]) * vis[vc[r]];
      if (m >= sum) {
        m -= sum;
        vis[vc[r - 1]] += vis[vc[r]];
        r--;
        maxs = vc[r];
      } else {
        long long x = m / vis[vc[r]];
        m = 0;
        mins = vc[r] + x;
      }
    }
  }
  cout << maxs - mins << endl;
  return 0;
}
