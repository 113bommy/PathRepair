#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const long long inf = 1e14;
long long a[maxn], sum[maxn];
map<long long, long long> map1;
set<long long> s;
int main(void) {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  s.insert(1);
  long long tmp = k;
  for (long long i = 1; i <= 60; i++) {
    if (tmp > inf) break;
    s.insert(tmp);
    tmp *= k;
  }
  long long ans = 0;
  map1[0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (set<long long>::iterator it = s.begin(); it != s.end(); it++) {
      ans += map1[sum[i] - *it];
    }
    map1[sum[i]]++;
  }
  cout << ans << endl;
  return 0;
}
