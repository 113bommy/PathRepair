#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s1[n], s2[n];
  for (int i = 0; i < n; i++) {
    cin >> s1[i] >> s2[i];
  }
  int ara[n];
  map<string, int> mp;
  map<string, int>::iterator it;
  for (int i = 0; i < n; i++) {
    cin >> ara[i];
  }
  string temp = min(s1[ara[0] - 1], s2[ara[0] - 1]);
  mp[temp] = 0;
  for (int i = 1; i < n; i++) {
    string mn = min(s1[ara[i] - 1], s2[ara[i] - 1]);
    string mx = max(s1[ara[i] - 1], s2[ara[i] - 1]);
    if (mn > temp) {
      mp[mn] = i;
      temp = mn;
    } else {
      mp[mx] = i;
      temp = mx;
    }
  }
  int d = 0;
  for (it = mp.begin(); it != mp.end(); it++, d++) {
    if (it->second != d) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
