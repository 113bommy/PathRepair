#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int l = s.size();
  int f = 0;
  map<int, int> mp;
  for (int i = 0; i < l / 2; i++) {
    if (s[i] != s[l - i - 1]) {
      f = 1;
    }
    mp[s[i]]++;
    mp[s[l - i - 1]]++;
  }
  if (f)
    cout << l << "\n";
  else {
    if (mp.size() == 1) {
      cout << "0\n";
    } else
      cout << l - 1 << "\n";
  }
  return 0;
}
