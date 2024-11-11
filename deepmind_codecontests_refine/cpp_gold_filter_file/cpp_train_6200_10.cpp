#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  vector<long long> pow_two(33);
  vector<long long> input(n);
  unordered_map<long long, long long> mp;
  for (int i = 0; i < n; i++) {
    cin >> input[i];
    mp[input[i]]++;
  }
  for (int i = 0; i < 33; i++) {
    pow_two[i] = 1ll << i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 32; j++) {
      auto tmp = pow_two[j] - input[i];
      if (tmp == input[i]) {
        ans += mp[tmp] - 1;
      } else {
        ans += mp[tmp];
      }
    }
  }
  ans >>= 1;
  cout << ans << endl;
  return 0;
}
