#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
const double pi = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(12);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    mp[a[i] - i] += a[i];
  }
  long long an = 10;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    an = max(an, it->second);
  }
  cout << an;
  return 0;
}
