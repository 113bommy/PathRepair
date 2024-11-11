#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  map<string, int> mapp;
  int max = 0;
  string ans;
  for (int i = 0; i < n - 1; i++) {
    string c = s.substr(i, 2);
    auto x = mapp.find(c);
    if (x == mapp.end())
      mapp[c] = 0;
    else {
      mapp[c]++;
      if (max < (x->second)) {
        max = x->second;
        ans = c;
      }
    }
  }
  if (max == 0) ans = s.substr(0, 2);
  cout << ans;
  return 0;
}
