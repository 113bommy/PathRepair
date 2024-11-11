#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    string s;
    cin >> s;
    if (s.length() < 4) {
      cout << 0 << endl;
    } else {
      map<char, int> mp;
      for (int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
      }
      int ans = 0;
      for (auto i : mp) {
        ans += min(2, i.second);
      }
      cout << ans / 2 << endl;
    }
  }
  return 0;
}
