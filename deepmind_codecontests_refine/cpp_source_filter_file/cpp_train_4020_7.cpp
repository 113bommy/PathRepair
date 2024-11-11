#include <bits/stdc++.h>
using namespace std;
long long int power[31] = {0};
long long int p1[31] = {0}, p2[31] = {0};
long long int xorval[31] = {0};
long long int tot = 0;
long long int query(vector<long long int> &v) {
  cout << "? ";
  tot++;
  assert(tot <= 19);
  cout << (long long int)v.size() << " ";
  for (auto u : v) cout << u << " ";
  cout << '\n';
  cout << flush;
  long long int x;
  cin >> x;
  return x;
}
void solve() {
  long long int n, x, y;
  cin >> n >> x >> y;
  long long int f = 10;
  for (long long int i = 0; i <= 9; i++) {
    vector<long long int> all;
    for (long long int j = 1; j <= n; j++) {
      if (power[i] & j) {
        all.push_back(j);
      }
    }
    if (all.empty()) continue;
    long long int res = query(all);
    xorval[i] = (res == (x ^ y) || (res == y));
    if (xorval[i]) f = min(f, i);
  }
  p2[f] = 1;
  for (long long int i = 0; i <= 9; i++) {
    if (i == f) continue;
    vector<long long int> all;
    for (long long int j = 1; j <= n; j++) {
      if ((power[i] & j) && (power[f] & j)) {
        all.push_back(j);
      }
    }
    if (all.empty()) continue;
    long long int res = query(all);
    p2[i] = ((res == (x ^ y)) || (res == y));
  }
  for (long long int i = 0; i <= 9; i++) p1[i] = (p2[i] ^ xorval[i]);
  cout << "! ";
  long long int res = 0;
  for (long long int i = 0; i <= 9; i++) res += p1[i] * power[i];
  cout << res << " ";
  res = 0;
  for (long long int i = 0; i <= 9; i++) res += p2[i] * power[i];
  cout << res << "\n";
  cout << flush;
  exit(0);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  power[0] = 1;
  for (long long int j = 1; j <= 10; j++) power[j] = power[j - 1] * 2;
  while (t--) {
    solve();
  }
  return 0;
}
