#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  for (long long i = 0; i < n; i++) cin >> a[i];
  if (n == 1 || n == 2) {
    cout << a[0];
    exit(0);
  }
  unordered_map<long long, long long> hm;
  for (long long i = 0; i < n; i++) hm[a[i]] = i;
  long long ans = INT_MAX;
  long long k = -1;
  for (auto [key, val] : hm) {
    if (ans > val) {
      ans = val;
      k = key;
    }
  }
  cout << k;
  return 0;
}
