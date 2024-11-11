#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9;
const double eps = 1e-10;
const int MX = 1e3 + 5;
int n, m, k, p, a[MX][MX];
long long bestr[MX * MX], bestc[MX * MX], psumr[MX * MX], psumc[MX * MX];
multiset<long long> sumr, sumc;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin >> n >> m >> k >> p;
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(m); ++j) cin >> a[i][j];
  for (int i = 0; i < int(n); ++i) {
    int sum = 0;
    for (int j = 0; j < int(m); ++j) sum += a[i][j];
    sumr.insert(sum);
  }
  for (int i = 0; i < int(m); ++i) {
    int sum = 0;
    for (int j = 0; j < int(n); ++j) sum += a[j][i];
    sumc.insert(sum);
  }
  for (int i = 1; i < int(k + 1); ++i) {
    long long maxr = *sumr.rbegin();
    long long maxc = *sumc.rbegin();
    bestr[i] = maxr;
    bestc[i] = maxc;
    sumr.erase(sumr.find(maxr));
    sumc.erase(sumc.find(maxc));
    sumr.insert(maxr - m * p);
    sumc.insert(maxc - n * p);
    psumr[i] = bestr[i] + psumr[i - 1];
    psumc[i] = bestc[i] + psumc[i - 1];
  }
  long long ans = -1e18;
  for (int i = 0; i < int(k + 1); ++i)
    ans = max(ans, psumr[i] + psumc[k - i] - i * p * 1LL * (k - i));
  cout << ans << '\n';
  return 0;
}
