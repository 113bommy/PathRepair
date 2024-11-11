#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int CASE = 1;
const int mxn = 1e5 + 1;
const long long INF = 1e18;
long long __gcd(long long a, long long b) { return !b ? a : __gcd(b, a % b); }
bool prime(long long n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i <= sqrt(n); i += 2)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  int n, k;
  cin >> n >> k;
  unordered_map<int, vector<int> > mp;
  int a[mxn], b[mxn];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mp[a[i]].push_back(b[i]);
  }
  for (auto& x : mp) {
    sort(x.second.begin(), x.second.end());
    x.second.pop_back();
  }
  vector<int> v;
  for (auto x : mp) {
    for (int i : x.second) v.push_back(i);
  }
  sort(v.begin(), v.end());
  int cnt = 0;
  for (int i = 0; i < k - mp.size(); i++) cnt += v[i];
  cout << cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
