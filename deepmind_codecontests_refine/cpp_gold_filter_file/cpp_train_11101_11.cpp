#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long N = 2e5 + 5;
long long n, m, k, cnt;
vector<long long> a, b;
vector<long long> fn(vector<long long> a, vector<long long> b) {
  a.push_back(0);
  long long lt = a.size() - 1;
  for (long long i = b.size() - 1; i >= 0; i--)
    a[lt] = (a[lt] + b[i]) % 2, lt--;
  return a;
}
void solve() {
  cin >> n;
  a.push_back(1);
  a.push_back(0);
  b.push_back(1);
  while (a.size() != n + 1) {
    b = fn(a, b);
    swap(a, b);
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  cout << a.size() - 1 << "\n";
  for (auto x : a) cout << x << " ";
  cout << "\n";
  cout << b.size() - 1 << "\n";
  for (auto x : b) cout << x << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) solve();
  return 0;
}
