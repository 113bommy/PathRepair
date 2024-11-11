#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i + 1 != v.size()) {
      os << " ";
    }
  }
  return os;
}
void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<ll> v = a;
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int m;
  cin >> m;
  while (m--) {
    int k, pos;
    cin >> k >> pos;
    --k;
    int mn = v[k];
    int j = k - 2;
    while (j >= 0 && v[k] == v[j]) {
      --j;
    }
    int cnt = k - j;
    for (int i = 0; i < n; ++i) {
      if (a[i] > mn) {
        --pos;
      } else if (a[i] == mn) {
        if (cnt > 0) {
          --pos;
          --cnt;
        }
      }
      if (pos == 0) {
        cout << a[i] << "\n";
        break;
      }
    }
  }
}
int main() {
  solve();
  return 0;
}
