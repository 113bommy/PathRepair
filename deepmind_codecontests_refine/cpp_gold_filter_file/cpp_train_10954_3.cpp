#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  unordered_map<long long, vector<long long>> m;
  for (long long i = 0; i < n; i++) {
    m[(i - v[i])].push_back(v[i]);
  }
  long long ans = 0;
  for (auto p : m) {
    long long sum = 0;
    for (auto x : p.second) sum += x;
    ans = max(ans, sum);
  }
  cout << ans;
  return 0;
}
