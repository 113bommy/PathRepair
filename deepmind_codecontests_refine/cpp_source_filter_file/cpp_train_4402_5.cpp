#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long res = 0;
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int num = 0;
  for (int step = 0; step < 30; ++step) {
    unordered_map<int, int> ones;
    unordered_map<int, int> zeroes;
    int res0 = 0, res1 = 0;
    for (int i = 0; i < n; ++i) {
      int key = v[i] >> 1;
      int value = v[i] & 1;
      if (value == 1) {
        ones[key]++;
        res1 += zeroes[key];
      } else {
        zeroes[key]++;
        res0 += ones[key];
      }
    }
    res += min(res0, res1);
    if (res1 < res0) num |= (1 << step);
    for (int i = 0; i < n; ++i) {
      v[i] >>= 1;
    }
  }
  cout << res << ' ' << num << endl;
  return 0;
}
