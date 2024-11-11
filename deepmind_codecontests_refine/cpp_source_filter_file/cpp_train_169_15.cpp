#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  map<string, int> mp;
  for (int i = 1; i < n; i++) {
    string tt = "";
    tt += str[i];
    tt += str[i - 1];
    mp[tt]++;
  }
  int cnt = -1;
  string ans;
  for (auto x : mp) {
    if (cnt < x.second) {
      cnt = x.second;
      ans = x.first;
    }
  }
  cout << ans << endl;
}
