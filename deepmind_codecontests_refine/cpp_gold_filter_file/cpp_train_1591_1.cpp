#include <bits/stdc++.h>
using namespace std;
template <typename G1, typename G2 = G1, typename G3 = G1>
struct triple {
  G1 first;
  G2 second;
  G3 T;
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> v = {0};
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    v.push_back(0);
    n += 2;
    auto val = [&](int p) {
      vector<int> w;
      for (int i = max(p - 1, 0); i <= min(n - 1, p + 1); i++)
        w.push_back(v[i]);
      sort(w.begin(), w.end());
      if (v[p] == w.back()) return v[p];
      if (v[p] == w[0]) return -v[p];
      return 0;
    };
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += val(i);
    cout << sum << '\n';
    while (q--) {
      int l, r;
      cin >> l >> r;
      if (l + 1 >= r) {
        for (int i = l - 1; i <= r + 1; i++) sum -= val(i);
      } else {
        for (int i = l - 1; i <= l + 1; i++) sum -= val(i);
        for (int i = r - 1; i <= r + 1; i++) sum -= val(i);
      }
      swap(v[l], v[r]);
      if (l + 1 >= r) {
        for (int i = l - 1; i <= r + 1; i++) sum += val(i);
      } else {
        for (int i = l - 1; i <= l + 1; i++) sum += val(i);
        for (int i = r - 1; i <= r + 1; i++) sum += val(i);
      }
      cout << sum << '\n';
    }
  }
  return 0;
}
