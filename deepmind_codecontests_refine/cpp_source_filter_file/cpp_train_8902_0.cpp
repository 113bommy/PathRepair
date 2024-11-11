#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  long long arr[n];
  cin >> s;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long visited[n];
  for (long long i = 0; i < n; i++) visited[i] = 0;
  long long cur = 0;
  visited[cur] = 1;
  for (long long i = 0; i < n; i++) {
    long long k = 1;
    if (s[cur] == '<') k = -1;
    cur += arr[i] * k;
    if (cur < 0 || cur > n - 1) {
      cout << "FINITE\n";
      return;
    }
    if (visited[cur] == 1) {
      cout << "INFINITE\n";
      return;
    }
    visited[cur] = 1;
  }
  cout << "FINITE\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  t = 1;
  while (t--) solve();
}
