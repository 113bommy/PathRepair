#include <bits/stdc++.h>
using namespace std;
using ull = long long;
int main() {
  int n, k;
  cin >> n >> k;
  int count_week = n - k + 1;
  vector<int> a(n);
  vector<int> ans(count_week);
  for (size_t i = 0; i < n; ++i) cin >> a[i];
  ull sum = 0;
  for (size_t j = 0; j < k; ++j) {
    ans[0] += a[j];
  }
  for (size_t l = 1; l < count_week; ++l) {
    ans[l] = ans[l - 1] - a[l - 1] + a[l + k - 1];
  }
  for (size_t m = 0; m < count_week; ++m) {
    sum += ans[m];
  }
  cout.precision(12);
  cout << (double)sum / (double)count_week;
  return 0;
}
