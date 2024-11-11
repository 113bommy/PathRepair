#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-10;
const double PI = 3.1415926535897932384626433832795;
const int CLK = CLOCKS_PER_SEC;
vector<long long> lnums;
const long long lm = 1000000000;
void dfs(long long v) {
  long long v1 = v * 10 + 4;
  long long v2 = v * 10 + 7;
  if (v1 <= lm) {
    lnums.push_back(v1);
    dfs(v1);
  }
  if (v2 <= lm) {
    lnums.push_back(v2);
    dfs(v2);
  }
}
int main() {
  long long pl, pr, vl, vr;
  int k;
  cin >> pl >> pr >> vl >> vr >> k;
  dfs(0);
  lnums.push_back(0);
  lnums.push_back(lm + 1LL);
  sort(lnums.begin(), lnums.end());
  int sz = lnums.size();
  double res = 0.0;
  for (int i = 1; i + k < sz; i++) {
    long long ar = lnums[i];
    long long al = lnums[i - 1];
    long long br = lnums[i + k];
    long long bl = lnums[i + k - 1];
    double p1 = (double)max(min(ar, pr) - max(al + 1, pl) + 1LL, 0LL) *
                max(min(br - 1, vr) - max(bl, vl) + 1LL, 0LL);
    double p2 = (double)max(min(br - 1, pr) - max(bl, pl) + 1LL, 0LL) *
                max(min(ar, vr) - max(al + 1, vl) + 1LL, 0LL);
    res += p1 + p2;
    if (k == 1 && pl <= ar && ar <= pr && vl <= ar && ar <= vr) res -= 1;
  }
  cout << fixed << setprecision(12) << res / ((vr - vl + 1) * (pr - pl + 1))
       << endl;
  return 0;
}
