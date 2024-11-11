#include <bits/stdc++.h>
const double eps = 1e-9;
const int mod = 1e9 + 7;
const int N = 30101;
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
long long gcd(long long x, long long y) { return (!y) ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return ((x / gcd(x, y)) * y); }
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n), ans;
  for (int i = 0; i < n; i++) cin >> v[i];
  sort((v).begin(), (v).end());
  int i = 0, j = n - 1;
  while (i < j) {
    ans.push_back(v[j--]);
    ans.push_back(v[i++]);
  }
  if (i == j) ans.push_back(v[i]);
  cout << ((int)ans.size() - 1) / 2 << "\n";
  for (auto k : ans) cout << k << " ";
  cout << "\n";
}
int main() {
  fast();
  solve();
  return 0;
}
