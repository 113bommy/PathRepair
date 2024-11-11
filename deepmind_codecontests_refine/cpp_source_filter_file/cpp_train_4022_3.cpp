#include <bits/stdc++.h>
using namespace std;
long long can;
long long n, a, d;
int m;
long long get_open_time(long long cur_time, long long tim, long long &ans) {
  long long idx = cur_time / a + 1;
  if (idx > n) {
    ans++;
    return tim;
  }
  long long last = tim / a;
  if (last < idx) {
    ans++;
    return tim;
  }
  last = min(last, n);
  long long tmp = (last - idx + can) / can;
  if (last == idx) {
    ans++;
    return min(idx * a, tim);
  }
  ans += tmp;
  return (idx + tmp * can) * a;
}
long long get_ost(long long cur_time) {
  long long idx = cur_time / a + 1;
  if (idx > n) return 0;
  long long ost = (n - idx + can) / can;
  return ost;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> a >> d;
  vector<long long> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  long long cur_time = 0;
  int idx = 0;
  long long ans = 0;
  long long cur_ev = 1;
  can = d / a + 1;
  while (idx < m) {
    long long open = get_open_time(cur_time, t[idx], ans);
    cur_time = open + d;
    while (idx < m && t[idx] <= cur_time) idx++;
    cur_ev = cur_time / a + 1;
  }
  ans += get_ost(cur_time);
  cout << ans;
  return 0;
}
