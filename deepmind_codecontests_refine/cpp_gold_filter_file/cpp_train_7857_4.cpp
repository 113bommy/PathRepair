#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  map<string, long long int> mp;
  long long int ans = 0;
  while (n--) {
    string s;
    cin >> s;
    mp[s]++;
    ans = max(ans, mp[s]);
  }
  cout << ans;
  return 0;
}
