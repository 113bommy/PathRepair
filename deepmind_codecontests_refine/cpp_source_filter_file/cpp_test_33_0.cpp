#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  bitset<1024> mp[501];
  bitset<1024> ans;
  ans.set(0);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]].set(arr[i]);
    ans.set(arr[i]);
    for (long long j = arr[i] - 1; j >= 0; j--) {
      mp[arr[i]] |= mp[j];
    }
    for (long long j = 0; j <= 500; j++) {
      if (mp[arr[i]].test(j)) {
        mp[arr[i]].set(arr[i] ^ j);
      }
    }
    ans |= mp[arr[i]];
  }
  cout << ans.count() << "\n";
  for (long long i = 0; i < 1024; i++) {
    if (ans.test(i)) {
      cout << i << " ";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  solve();
  return 0;
}
