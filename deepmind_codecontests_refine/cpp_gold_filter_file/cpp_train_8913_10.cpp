#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline istream& operator>>(istream& is, vector<T>& v) {
  for (auto& e : v) {
    cin >> e;
  }
  return is;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  int o = 0, t = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ++o;
    } else {
      ++t;
    }
  }
  int m = min(o, t);
  cout << m + (o - m) / 3;
  return 0;
}
