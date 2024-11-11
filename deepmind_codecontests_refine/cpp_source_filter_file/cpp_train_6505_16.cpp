#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
long long a[N];
long long n, m;
bool can(long long k) {
  queue<pair<long long, long long>> qu;
  for (long long i = 1; i <= n; ++i)
    if (a[i] != 0) qu.push({a[i], i});
  vector<long long> pos(m + 1, 0), how(m + 1);
  for (long long i = 1; i <= m;) {
    if (qu.empty()) return true;
    long long cnt = qu.front().first, p = qu.front().second;
    long long tim = p - pos[i] + how[i];
    long long walk = p - pos[i];
    if (tim < k) {
      pos[i] = p;
      long long rem = k - tim;
      if (rem >= cnt) {
        qu.pop();
        how[i] += walk + cnt;
      } else {
        qu.front().first -= rem;
        ++i;
      }
    } else {
      ++i;
    }
  }
  return qu.empty();
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  long long l = 0, r = 1e9 + 7;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (can(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
}
