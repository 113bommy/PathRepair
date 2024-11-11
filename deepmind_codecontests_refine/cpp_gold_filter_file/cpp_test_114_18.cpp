#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int ALPHA = 40;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int LOG = 22;
int n;
int ns[MAXN];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ns[i];
  sort(ns, ns + n);
  for (int i = 1; i < (n / 2) + 1; i++) cout << ns[i] << ' ' << ns[0] << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
