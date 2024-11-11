#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  for (char c : s) {
    mp[c]++;
  }
  long long ans = 0;
  for (auto x : mp) {
    ans += (x.second * x.second);
  }
  cout << ans;
}
