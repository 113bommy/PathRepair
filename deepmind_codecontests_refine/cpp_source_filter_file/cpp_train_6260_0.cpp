#include <bits/stdc++.h>
using namespace std;
long long n, x;
long long a[300005];
map<pair<long long, long long>, long long> mapy;
int main() {
  cin >> n;
  long long res = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> x;
    res ^= x;
    mapy[{res, i % 2}]++;
  }
  int ans = 0;
  for (map<pair<long long, long long>, long long>::iterator it = mapy.begin();
       it != mapy.end(); it++) {
    if (it->first.first == 0 && it->first.second == 0) ans += it->second;
    ans += (it->second) * (it->second - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
