#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T;
  cin >> T;
  long long int ans = 0;
  map<long long int, long long int> mp;
  for (int i = 1; i <= T; i++) {
    long long int temp;
    cin >> temp;
    ans = max(ans, temp);
    mp[i - temp] += temp;
  }
  for (auto i : mp) {
    ans = max(ans, i.second);
  }
  cout << ans << endl;
}
