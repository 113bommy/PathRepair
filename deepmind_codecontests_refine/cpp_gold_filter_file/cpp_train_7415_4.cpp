#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long int LINF = 1e18;
void solve() {
  long long int n, i, j, k, m, x, y, s, c;
  cin >> n >> k;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  m = 0;
  for (i = n - k + 1; i <= n; i++) {
    m += i;
  }
  cout << m << ' ';
  m = 998244353;
  j = n - k + 1;
  vector<long long int> v;
  for (i = 0; i < n; i++) {
    if (a[i] >= j) v.push_back(i);
  }
  k = 1;
  for (i = 1; i < v.size(); i++) {
    k = (k % m) * ((v[i] - v[i - 1]) % m);
  }
  cout << k % m << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
