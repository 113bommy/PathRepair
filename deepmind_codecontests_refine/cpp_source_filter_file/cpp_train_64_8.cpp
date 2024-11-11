#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int curr_len = 0;
  int l = 0, r = a.size() - 1;
  while (l <= r) {
    if (a[l] < int(1e6) - a[r]) {
      curr_len = a[l] - 1;
      ++l;
    } else {
      curr_len = int(1e6) - a[r];
      --r;
    }
  }
  cout << curr_len;
  return 0;
}
