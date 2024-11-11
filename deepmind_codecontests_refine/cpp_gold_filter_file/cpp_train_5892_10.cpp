#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1000000000;
int main() {
  int n;
  cin >> n;
  vector<ll> neg_max{-INF, -INF};
  vector<ll> pos_min{INF, INF};
  vector<ll> a(n);
  for (ll &ai : a) {
    cin >> ai;
  }
  ll sum = accumulate(a.begin(), a.end(), 0, [](int prev, int curr) {
    return (curr > 0) ? curr + prev : prev;
  });
  for (ll ai : a) {
    if (ai < 0) {
      neg_max[ai & 1] = max(neg_max[ai & 1], ai);
    } else {
      pos_min[ai & 1] = min(pos_min[ai & 1], ai);
    }
  }
  if (sum & 1) {
    cout << sum << endl;
  } else if (neg_max[1] == -INF) {
    cout << sum - pos_min[1] << endl;
  } else if (pos_min[1] == INF) {
    cout << sum + neg_max[1] << endl;
  } else {
    cout << max(sum - pos_min[1], sum + neg_max[1]) << endl;
  }
  return 0;
}
