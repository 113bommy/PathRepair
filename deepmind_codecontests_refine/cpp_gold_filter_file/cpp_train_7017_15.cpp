#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    map<int, int>::iterator ac = mp.find(a);
    map<int, int>::iterator bc = mp.find(b);
    map<int, int>::iterator cc = mp.find(c);
    if (ac == mp.end() && bc == mp.end() && cc == mp.end()) {
      mp[a] = 1;
      mp[b] = 2;
      mp[c] = 3;
      continue;
    }
    if (ac != mp.end()) {
      if (ac->second == 1) {
        mp[b] = 2;
        mp[c] = 3;
      } else if (ac->second == 2) {
        mp[b] = 1;
        mp[c] = 3;
      } else if (ac->second == 3) {
        mp[b] = 1;
        mp[c] = 2;
      }
    } else if (bc != mp.end()) {
      if (bc->second == 1) {
        mp[a] = 2;
        mp[c] = 3;
      } else if (bc->second == 2) {
        mp[a] = 1;
        mp[c] = 3;
      } else if (bc->second == 3) {
        mp[a] = 1;
        mp[c] = 2;
      }
    } else if (cc != mp.end()) {
      if (cc->second == 1) {
        mp[b] = 2;
        mp[a] = 3;
      } else if (cc->second == 2) {
        mp[b] = 1;
        mp[a] = 3;
      } else if (cc->second == 3) {
        mp[b] = 1;
        mp[a] = 2;
      }
    }
  }
  for (typeof((mp).begin()) it = (mp).begin(); it != (mp).end(); it++)
    cout << it->second << " ";
  cout << endl;
  return 0;
}
