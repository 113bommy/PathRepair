#include <bits/stdc++.h>
using namespace std;
const long long int mod = 212072634227239451;
vector<long long int> ans;
bool prime(long long int s) {
  if (s <= 1) return false;
  if (s <= 3) return true;
  if (s % 2 == 0 || s % 3 == 0) return false;
  for (long long int i = 5; i * i <= s; i = i + 6)
    if (s % i == 0 || s % (i + 2) == 0) return false;
  return true;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool square(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
const long long int sz = 1e4;
bool vis[sz];
void solve() {
  long long int n;
  cin >> n;
  long long int ans = 0;
  long long int arr[n];
  map<long long int, long long int> make_pair;
  for (long long int i = 0; i < n; ++i) {
    cin >> arr[i];
    make_pair[arr[i]]++;
  }
  for (auto m : make_pair) {
    ans += max(0ll, m.second - 1);
  }
  cout << ans + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
