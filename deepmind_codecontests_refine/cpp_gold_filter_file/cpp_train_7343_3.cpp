#include <bits/stdc++.h>
using namespace std;
int64_t n, x;
vector<int64_t> v;
void init() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  v.resize(n);
  for (int64_t i = 0; i < n; ++i) {
    cin >> v[i];
  }
}
void solve() {
  for (int64_t i = 0; i < v.size(); ++i) {
    for (int64_t j = v.size() - 1; j > i; --j) {
      if (v[j] < v[j - 1]) {
        swap(v[j], v[j - 1]);
        cout << (j) << " " << (j + 1) << endl;
      }
    }
  }
}
int32_t main() {
  init();
  solve();
  return 0;
}
