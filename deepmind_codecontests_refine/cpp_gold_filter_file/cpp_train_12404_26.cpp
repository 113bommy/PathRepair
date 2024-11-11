#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 7;
const long long MOD = 1e9 + 7;
void solve();
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
void solve() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> s(n);
  for (int &i : s) cin >> i;
  vector<int> b(m);
  for (int &i : b) cin >> i;
  int min = *min_element(s.begin(), s.end());
  int max = *max_element(b.begin(), b.end());
  cout << std::max(r, r + (max - min) * (r / min));
}
