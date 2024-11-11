#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a, b;
  for (long long &i : a) cin >> i;
  for (long long &i : b) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (long long &i : a) cout << i << ' ';
  cout << endl;
  for (long long &i : b) cout << i << ' ';
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long n = 1;
  cin >> n;
  while (n--) solve();
  return 0;
}
