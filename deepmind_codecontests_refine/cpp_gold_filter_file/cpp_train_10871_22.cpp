#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const double infd = 2e+9;
const int infi = INT_MAX;
template <class T>
inline T sqr(T x) {
  return x * x;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int max_d = 2e+4 + 1;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int res = infi, res_d, res_begin;
  for (int d = 0; d < max_d; d++) {
    int mi = infi, ma = -infi;
    for (int i = 0; i < n; i++) {
      int x = a[i] - i * d;
      mi = min(mi, x);
      ma = max(ma, x);
    }
    int local_res = (ma - mi) - (ma - mi) / 2;
    if (local_res < res) {
      res = local_res;
      res_d = d;
      res_begin = (ma + mi) / 2;
    }
  }
  cout << res << endl << res_begin << ' ' << res_d;
  return 0;
}
