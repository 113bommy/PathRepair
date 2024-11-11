#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, maxi(0), m;
  string s, now = "", ans = "";
  cin >> m >> s;
  map<string, int> mp;
  n = s.size();
  for (int i = 0; i < n - 1; i++) {
    now = s.substr(i, 2);
    mp[now]++;
  }
  map<string, int>::iterator it;
  for (it = mp.begin(); it != mp.end(); it++) {
    if (it->second > maxi) {
      maxi = it->second;
      ans = it->first;
    }
  }
  cout << ans << "\n";
  return 0;
}
