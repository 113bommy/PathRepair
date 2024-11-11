#include <bits/stdc++.h>
using namespace std;
long long n, m;
map<long long, bool> mp;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    long long sum = 0, mask = 0;
    for (long long j = 0; j < m; j++) {
      long long x;
      cin >> x;
      mask |= (1 << j) * x;
      sum += x;
    }
    mp[mask] = true;
    if (!sum) return cout << "YES\n", 0;
  }
  for (long long i = 0; i < (1 << m); i++) {
    for (long long j = 0; j < (1 << m); j++) {
      if (mp[i] && mp[j] && i + j == i ^ j) return cout << "YES\n", 0;
    }
  }
  cout << "NO\n";
}
