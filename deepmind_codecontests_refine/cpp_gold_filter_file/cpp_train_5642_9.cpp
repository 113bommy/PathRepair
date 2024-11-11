#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
bool check(char a, char b, char c) {
  int ans = (a - 48) * 100 + (b - 48) * 10 + (c - 48);
  return (ans % 8 == 0 ? true : false);
}
void solve() {
  int n, k, d;
  cin >> n >> k >> d;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int lptr = 0, rptr = d;
  int cnt = 0;
  int best = INT_MAX;
  map<int, int> mp;
  for (int i = lptr; i < rptr; i++) {
    mp[a[i]]++;
    if (mp[a[i]] == 1) cnt++;
  }
  best = cnt;
  while (rptr < n) {
    mp[a[rptr]]++;
    if (mp[a[rptr]] == 1) cnt++;
    rptr++;
    mp[a[lptr]]--;
    if (mp[a[lptr]] == 0) cnt--;
    lptr++;
    best = min(best, cnt);
  }
  cout << best << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
