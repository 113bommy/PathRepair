#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
struct sortgreater {
  template <class T>
  bool operator()(T const &a, T const &b) const {
    return a > b;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), sortgreater());
  for (int i = 0; i < n; i++) {
    if (m >= 0) {
      ans++;
      m -= a[i];
    }
  }
  cout << ans;
  return 0;
}
