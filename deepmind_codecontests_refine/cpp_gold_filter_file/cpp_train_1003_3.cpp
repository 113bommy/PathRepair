#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<long long> arr;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  std::vector<long long> v;
  long long t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  for (long long i = 0; i < v.size() - 1; i++) {
    if (abs(v[i + 1] - v[i]) >= 2) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}
