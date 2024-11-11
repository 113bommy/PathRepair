#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string a;
  cin >> a;
  if (a.length() < 4) {
    cout << "No";
    return 0;
  }
  map<char, int> map1;
  for (int i = 0; i < a.length(); i++) {
    if (map1.find(a[i]) == map1.end())
      map1.insert({a[i], 1});
    else
      map1[a[i]]++;
    if (map1.size() > 4) {
      cout << "No";
      return 0;
    }
  }
  int x = map1.size();
  if (x == 3 || x == 4) {
    cout << "Yes";
    return 0;
  }
  if (x == 1) {
    cout << "No";
    return 0;
  }
  if (x == 2) {
    for (auto i = map1.begin(); i != map1.end(); i++)
      if (i->second < 2) {
        cout << "No";
        return 0;
      }
    cout << "Yes";
    return 0;
  }
}
