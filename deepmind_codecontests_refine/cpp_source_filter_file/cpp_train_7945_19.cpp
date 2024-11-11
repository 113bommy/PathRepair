#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, x, y;
  cin >> n;
  std::vector<long long> XC;
  std::vector<long long> YC;
  for (long long i = 0; i < n; i++) {
    cin >> x >> y;
    XC.push_back(x);
    YC.push_back(y);
  }
  long long rn = 0, ln = 0, un = 0, dn = 0, sc = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (XC[i] == XC[j] && YC[i] > YC[j]) dn++;
      if (XC[i] == XC[j] && YC[i] < YC[j]) un++;
      if (XC[i] < XC[j] && YC[i] == YC[j]) rn++;
      if (XC[i] > XC[j] && YC[i] == YC[j]) ln++;
    }
    if (dn && un && rn && ln) {
      sc++;
    }
    dn = 0;
    un = 0;
    un = 0;
    ln = 0;
  }
  cout << sc;
  return 0;
}
