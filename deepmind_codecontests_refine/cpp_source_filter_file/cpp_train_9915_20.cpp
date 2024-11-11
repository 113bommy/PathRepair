#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    vector<int> p(n + 1);
    for (auto& a : v) {
      cin >> a;
    }
    p[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
      p[i] += p[i - 1];
      if (i >= 2 && i + 1 < n && v[i - 1] > v[i - 2] && v[i - 1] > v[i]) {
        ++p[i];
      }
    }
    int rp = 0, l = n - k + 1, lres;
    while (l >= 0) {
      int r = l + k - 1;
      int ps = p[r] - p[l];
      if (r < n && v[r - 1] > v[r - 2] && v[r - 1] > v[r]) {
        --ps;
      }
      if (ps >= rp) {
        lres = l;
        rp = ps;
      }
      --l;
    }
    cout << ++rp << ' ' << lres << endl;
  }
  return 0;
}
