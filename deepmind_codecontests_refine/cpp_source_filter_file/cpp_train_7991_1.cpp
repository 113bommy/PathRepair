#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int l = 0, r = 1001001001;
  while (r - l > 1) {
    int c = (l + r) / 2;
    auto ok = [&] {
      long long cnt = 0;
      for (int i = 0; i < n; i++) cnt += a[i] / c;
      return cnt <= k;
    };
    (ok(c) ? r : l) = c;
  }
  cout << r << endl;
  return 0;
}