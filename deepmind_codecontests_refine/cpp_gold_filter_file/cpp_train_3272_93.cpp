#include <bits/stdc++.h>
using namespace std;
const int64_t inf = 1e9;
signed main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int64_t i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
