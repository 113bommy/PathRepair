#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const double PI = acos(-1);
long long gcd() { return 0ll; }
template <typename T, typename... Args>
T gcd(T a, Args... args) {
  return __gcd(a, (__typeof(a))gcd(args...));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    int n, m, w;
    cin >> n >> m;
    int res[8] = {0};
    pair<int, int> a[m];
    for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
         i += 1 - 2 * ((0) > (m)))
      cin >> a[i].first >> a[i].second;
    sort(a, a + m);
    map<int, int> hsuf, vsuf, ldsuf, rdsuf;
    map<int, int> hpre, vpre, ldpre, rdpre;
    for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
         i += 1 - 2 * ((0) > (m))) {
      hsuf[a[i].first]++;
      vsuf[a[i].second]++;
      ldsuf[a[i].first + a[i].second]++;
      rdsuf[a[i].first - a[i].second]++;
    }
    for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
         i += 1 - 2 * ((0) > (m))) {
      hsuf[a[i].first]--;
      vsuf[a[i].second]--;
      ldsuf[a[i].first + a[i].second]--;
      rdsuf[a[i].first - a[i].second]--;
      w = (hpre[a[i].first] > 0) + (hsuf[a[i].first] > 0) +
          (vpre[a[i].second] > 0) + (vsuf[a[i].second] > 0);
      w += (ldpre[a[i].first + a[i].second] > 0) +
           (rdpre[a[i].first - a[i].second] > 0);
      w += (ldsuf[a[i].first + a[i].second] > 0) +
           (rdsuf[a[i].first - a[i].second] > 0);
      res[w]++;
      hpre[a[i].first]++;
      vpre[a[i].second]++;
      ldpre[a[i].first + a[i].second]++;
      rdpre[a[i].first - a[i].second]++;
    }
    for (__typeof(8) i = (0) - ((0) > (8)); i != (8) - ((0) > (8));
         i += 1 - 2 * ((0) > (8)))
      cout << res[i] << " ";
    cout << "\n";
  }
  return 0;
}
