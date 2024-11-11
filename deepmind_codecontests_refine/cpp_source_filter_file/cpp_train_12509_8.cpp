#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long double eps = 1e-9;
const double pi = acos(-1);
void solve() {
  long long int a[] = {4, 8, 15, 16, 23, 42};
  map<long long int, long long int> mp;
  map<long long int, long long int> ind;
  long long int b = 0;
  for (auto i : a) ind[i] = b++;
  long long int n;
  cin >> n;
  long long int c;
  for (long long int i = 0; i < (long long int)(n); ++i) {
    cin >> b;
    c = ind[b];
    if (c == 0 || mp[a[c - 1]] >= mp[b]) mp[b]++;
  }
  c = mp[4];
  for (auto i : a) {
    c = min(mp[i], c);
  }
  n -= c * 6;
  cout << n << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) solve();
  fflush(stdout);
  return 0;
}
