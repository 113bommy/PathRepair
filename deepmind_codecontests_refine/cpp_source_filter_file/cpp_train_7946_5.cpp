#include <bits/stdc++.h>
using namespace std;
std::vector<pair<long double, int> > v;
int main() {
  long double n, t, tt, k, m, a, b;
  cin >> n >> t >> tt >> k;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    m = max(a * t - (k * (a * t) / 100) + b * tt,
            b * t - (k * (b * t) / 100) + a * tt);
    v.push_back({m, -i});
  }
  sort(v.begin(), v.end());
  for (int i = n - 1; i >= 0; --i) {
    printf("%d %.2f\n", (-v[i].second) + 1, v[i].first);
  }
}
