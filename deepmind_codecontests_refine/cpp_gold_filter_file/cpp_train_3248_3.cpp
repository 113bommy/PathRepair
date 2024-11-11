#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  ;
  vector<int> a(n);
  for (__typeof(0) i = 0; i < n; i++) cin >> a[i];
  ;
  vector<int> days;
  vector<int> status(1000005);
  int inside_cnt = 0;
  int day_cnt = 0;
  int k = 0;
  for (__typeof(0) i = 0; i < n; i++) {
    day_cnt++;
    if (a[i] > 0) {
      if (status[a[i]] <= k) {
        status[a[i]] = k + 1;
        inside_cnt++;
      } else {
        cout << -1;
        return 0;
      }
    } else {
      a[i] = -a[i];
      if (status[a[i]] == k + 1) {
        status[a[i]] = k + 2;
        inside_cnt--;
      } else {
        cout << -1;
        return 0;
      }
    }
    if (inside_cnt == 0) {
      days.push_back(day_cnt);
      day_cnt = 0;
      k += 2;
    }
  }
  int s = 0;
  for (auto& x : days) s += x;
  if (s == n) {
    cout << days.size() << '\n';
    for (auto& x : days) cout << x << ' ';
    cout << '\n';
    ;
  } else {
    cout << -1;
  }
  return 0;
}
