#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i, count = 0;
  map<char, int> mp;
  for (i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second > 1) {
      count += (it->second) - 1;
    }
  }
  if (count >= 26)
    cout << -1 << endl;
  else
    cout << count << endl;
}
