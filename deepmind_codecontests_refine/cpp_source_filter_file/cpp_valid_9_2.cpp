#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    string s, s1;
    cin >> s;
    map<char, int> mp;
    long long n = s.size();
    for (long long i = 0; i < n; i++) {
      mp[s[i]]++;
    }
    long long dis = 0, com = 0;
    for (auto x : mp) {
      if (x.second >= 2)
        com++;
      else if (x.second == 1)
        dis++;
    }
    cout << com + (dis / 2);
  }
}
