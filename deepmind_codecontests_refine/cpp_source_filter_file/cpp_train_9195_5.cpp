#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, t;
vector<pair<ll, int>> edges;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> t;
  edges.resize(k);
  for (int i = 0; i < k; i++) {
    int h, w, r;
    cin >> h >> w >> r;
    h--;
    w--;
    ll mask = ll(1) << h;
    mask |= ll(1) << (n + w);
    edges[i] = {r, mask};
  }
  sort(edges.begin(), edges.end());
  int s = -1, e = n * 1000;
  while (s + 1 < e) {
    int mid = (s + e) / 2;
    int tot = 1;
    function<void(int, int, ll)> enumerate = [&](int cur, int cur_cost,
                                                 ll mask) {
      if (cur == k) return;
      if (tot >= t) return;
      int new_cost = cur_cost + edges[cur].first;
      if (new_cost <= mid) {
        if (!(mask & edges[cur].second)) {
          tot += 1;
          enumerate(cur + 1, new_cost, mask | edges[cur].second);
        }
        enumerate(cur + 1, cur_cost, mask);
      }
    };
    enumerate(0, 0, 0);
    if (tot >= t) {
      e = mid;
    } else {
      s = mid;
    }
  }
  cout << e << '\n';
}
