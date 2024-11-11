#include <bits/stdc++.h>
using namespace std;
template <typename T>
int len(const T& a) {
  return a.size();
}
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    long long w;
    cin >> n >> w;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    if (n == 1) {
      if (a[0] < (w + 1) / 2)
        cout << -1 << '\n';
      else if (a[0] <= w)
        cout << 1 << '\n' << 1 << '\n';
      else
        cout << -1 << '\n';
      continue;
    }
    vector<int> ind(a.size());
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(),
         [&](int lhs, int rhs) { return a[lhs] < a[rhs]; });
    while (!ind.empty() && a[ind.back()] > w) ind.pop_back();
    if (ind.empty()) {
      cout << -1 << '\n';
      continue;
    }
    long long mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 0; i < len(ind); ++i) {
      mn = min(mn, (long long)a[ind[i]]);
      mx = max(mx, (long long)a[ind[i]]);
    }
    if (mx < (w + 1) / 2) {
      long long sum = 0;
      vector<int> idx;
      for (int i = len(ind) - 1; i >= 0 && sum < (w + 1) / 2; --i) {
        sum += a[ind[i]];
        idx.push_back(ind[i] + 1);
      }
      if (sum < (w + 1) / 2 || sum > w) {
        cout << -1 << '\n';
        continue;
      }
      cout << len(idx) << '\n';
      for (auto& i : idx) cout << i << ' ';
    } else {
      int idx = -1;
      for (int i = len(ind) - 1; i >= 0; --i) {
        if (a[ind[i]] >= (w + 1) / 2) {
          idx = ind[i] + 1;
          break;
        }
      }
      if (idx == -1) {
        cout << -1 << '\n';
        continue;
      }
      cout << 1 << '\n' << idx << '\n';
    }
  }
  return 0;
}
