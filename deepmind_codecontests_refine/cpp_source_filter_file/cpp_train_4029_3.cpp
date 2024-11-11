#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int powe(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
void solve() {
  long long int i, j, k = 0, n, m, l;
  cin >> n;
  vector<vector<long long int> > v(n + 1);
  for (i = 0; i < n - 1; i++) {
    cin >> j >> k;
    v[j].push_back(k);
    v[k].push_back(j);
  }
  long long int md = 0;
  vector<long long int> leaf;
  long long int root = -1;
  for (i = 1; i <= n; i++) {
    j = v[i].size();
    if (j <= 3) continue;
    md++;
    if (root != -1) {
      cout << "No" << endl;
      return;
    }
    root = i;
  }
  if (root == -1) {
    root = 1;
  }
  cout << "Yes" << endl;
  vector<long long int> ans;
  for (i = 1; i <= n; i++) {
    if (i != root && v[i].size() == 1) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) {
    cout << root << " " << ans[i] << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j, l, k, t, n;
  t = 1;
  while (t--) solve();
}
