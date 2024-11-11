#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, string> mp;
  int n;
  string x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (mp.count(x) == false) {
      mp[y] = x;
    } else {
      mp[y] = mp[x];
      mp.erase(x);
    }
  }
  cout << mp.size() << endl;
  for (auto z : mp) {
    cout << z.second << " " << z.first << endl;
  }
}
