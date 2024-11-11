#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const long long INF64 = (long long)1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
const int maxn = 300000;
const int maxval = 1000000;
int n, k;
int cnt[maxval + 1];
vector<int> a;
bool read() {
  if (scanf("%d%d", &n, &k) != 2) return false;
  a.assign(n, 0);
  for (int i = 0; i < int(n); ++i) scanf("%d", &a[i]);
  return true;
}
void solve() {
  memset(cnt, 0, sizeof cnt);
  sort((a).begin(), (a).end());
  for (int i = 0; i < int((int)(a).size()); ++i) cnt[a[i]]++;
  for (int i = 1; i <= maxval; i++) {
    cnt[i] += cnt[i - 1];
  }
  int ans = 1;
  for (int i = 2; i <= 10; i++) {
    int tcnt = 0;
    int lf = i, rg = i;
    for (int j = i; j <= maxval; j += i) {
      if (j <= rg)
        rg = max(j + k, rg);
      else {
        tcnt += cnt[rg] - cnt[lf - 1];
        lf = j;
        rg = j + k;
      }
      rg = min(rg, maxval);
    }
    tcnt += cnt[rg] - cnt[lf - 1];
    if (tcnt == n) ans = max(ans, i);
  }
  cout << ans;
}
int main() {
  while (read()) solve();
  return 0;
}
