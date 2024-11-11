#include <bits/stdc++.h>
using namespace std;
using Int = long long;
using Float = long double;
void solve() {
  Int n, k;
  cin >> n >> k;
  vector<pair<Int, Int>> A;
  A.push_back(make_pair(0, 0));
  {
    map<Int, Int> mp;
    for (Int(i) = (1); (i) <= (n); (i)++) {
      Int a;
      cin >> a;
      mp[a]++;
    }
    for (auto x : mp) {
      A.push_back(x);
    }
  }
  A.push_back(make_pair(200001, 0));
  Int m = A.size() - 2;
  vector<Int> cuml(m + 2), cumr(m + 2), cntl(m + 2), cntr(m + 2);
  for (Int(i) = (1); (i) <= (m); (i)++) {
    cuml[i] = cuml[i - 1] + A[i].first * A[i].second;
    cntl[i] = cntl[i - 1] + A[i].second;
  }
  for (Int(i) = (m); (i) >= (1); (i)--) {
    cumr[i] = cumr[i + 1] + A[i].first * A[i].second;
    cntr[i] = cntr[i + 1] + A[i].second;
  }
  Int res = Int(1e16);
  for (Int(i) = (1); (i) <= (m); (i)++) {
    Int need = max(0LL, k - A[i].second);
    if (need == 0) {
      cout << 0 << "\n";
      return;
    }
    {
      if (cuml[i - 1] >= need) {
        Int sumk = need * A[i].first;
        Int sumkm1 = (cntl[i - 1] - need) * (A[i].first - 1);
        res = min(res, sumk + sumkm1 - cuml[i - 1]);
      } else {
        Int resl = cntl[i - 1] * A[i].first - cuml[i - 1];
        Int needr = need - cntl[i - 1];
        Int sumkr = needr * A[i].first;
        Int sumkrp1 = (cntr[i + 1] - needr) * (A[i].first + 1);
        Int resr = cumr[i + 1] - (sumkr + sumkrp1);
        res = min(res, resl + resr);
      }
    }
    {
      if (cumr[i + 1] >= need) {
        Int sumk = need * A[i].first;
        Int sumkp1 = (cntr[i + 1] - need) * (A[i].first + 1);
        res = min(res, cumr[i + 1] - (sumk + sumkp1));
      } else {
        Int resr = cumr[i + 1] - cntr[i + 1] * A[i].first;
        Int needl = need - cntr[i + 1];
        Int sumkl = needl * A[i].first;
        Int sumklm1 = (cntl[i - 1] - needl) * (A[i].first - 1);
        Int resl = sumkl + sumklm1 - cuml[i - 1];
        res = min(res, resr + resl);
      }
    }
  }
  cout << res << "\n";
  return;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
