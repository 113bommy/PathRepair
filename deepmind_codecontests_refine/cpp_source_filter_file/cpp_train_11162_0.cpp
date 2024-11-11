#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  bool first = true;
  for (const auto& j : v) {
    if (!first) {
      os << " ";
    }
    first = false;
    os << j;
  }
  os << "\n";
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& elem : v) {
    is >> elem;
  }
  return is;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  if (n % 2) {
    cout << "NO";
    return;
  }
  n = n / 2;
  for (int i = 0; i < n - 1; i++) {
    long long x1 = a[i + 1].first - a[i].first;
    long long y1 = a[i + 1].second - a[i].second;
    long long x2 = a[n + i + 1].first - a[n + i].first;
    long long y2 = a[n + i + 1].second - a[n + i].second;
    if (x1 != -x1 || y1 != -y2) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
int main() {
  if (0) {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
      solve();
      cout << "\n";
    }
  } else {
    solve();
    cout << endl;
  }
  return 0;
}
