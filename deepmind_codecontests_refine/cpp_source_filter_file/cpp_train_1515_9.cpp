#include <bits/stdc++.h>
using namespace std;
int N, M, T, K;
int main() {
  ios::sync_with_stdio(false);
  map<int, int> mp;
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    int x;
    cin >> x;
    mp[x]++;
    sum += x;
  }
  int ans = sum;
  for (auto e : mp) {
    if (e.second == 4) {
      ans = min(ans, sum - e.first * 3);
    } else if (e.second >= 2) {
      ans = min(ans, sum - e.second * e.first);
    }
  }
  cout << ans;
}
