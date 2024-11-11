#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  string s, a;
  cin >> n >> s;
  map<string, int> mp;
  for (int i = 1; i < n; i++) {
    string t = s.substr(i - 1, 2);
    if (mp.find(t) == mp.end())
      mp[t] = 0;
    else
      mp[t] = mp[t] + 1;
    if (ans <= mp[t]) {
      ans = mp[t];
      a = t;
    }
  }
  cout << a << endl;
  return 0;
}
