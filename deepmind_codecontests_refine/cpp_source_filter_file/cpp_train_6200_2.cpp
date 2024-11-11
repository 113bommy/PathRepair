#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long target = 2;
    while (target < (1LL << 11)) {
      ans += (upper_bound(v.begin() + i + 1, v.end(), -v[i] + target)) -
             (lower_bound(v.begin() + i + 1, v.end(), -v[i] + target));
      target <<= 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
