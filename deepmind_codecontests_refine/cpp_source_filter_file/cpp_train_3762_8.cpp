#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
  }
  cout << res / 2;
  return 0;
}
