#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MX = 1e3 + 5;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long tg = (n - 1) / (k * k + 1);
  vector<long long> dg;
  while (tg > 0) {
    dg.push_back(tg % k);
    tg /= k;
  }
  dg.push_back(0);
  reverse(dg.begin(), dg.end());
  tg = (n - 1) / (k * k + 1);
  map<long long, long long> sm;
  long long cr = 0, crsm = k * (k + 1) / 2;
  for (long long i : dg) {
    long long tn = i, bs = cr * (k * k + 1);
    long long nxsm = -1;
    long long lf = bs + tn * k + 1, rg = bs + tn * k + k;
    if (rg < crsm)
      nxsm = (bs + tn * k) * k + k * (k + 1) / 2;
    else if (crsm < lf)
      nxsm = (bs + tn * k) * k + k * (k + 1) / 2 + k;
    else {
      nxsm = (bs + tn * k) * (k + 1) + (k + 1) * (k + 2) / 2 - crsm;
    }
    sm[nxsm] = cr * k * (k + 1) + tn * (k + 1) + (k + 1);
    cr = k * cr + tn;
    crsm = nxsm;
  }
  long long ans, bs = tg * (k * k + 1);
  if (n == crsm)
    ans = sm[n];
  else {
    if (n > crsm) n--;
    long long tn = (n - bs - 1) / k;
    ans = cr * k * (k + 1) + tn * (k + 1) + (n - bs - 1) % k + 1;
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tc;
  cin >> tc;
  for (; tc--;) solve();
}
