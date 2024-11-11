#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > arr;
map<pair<int, int>, int> mp;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  mp[make_pair(a, b)] = 1;
  mp[make_pair(c, d)] = 1;
  mp[make_pair(e, f)] = 1;
  for (int i = -1000; i <= 1000; i++) {
    for (int j = -1000; j <= 1000; j++) {
      int x = a + i;
      int y = b + j;
      if (x == (c + e) && y == (d + f)) {
        if (mp[make_pair(i, j)] == 0) arr.push_back(make_pair(i, j));
        mp[make_pair(i, j)] = 1;
      }
      x = (c + i);
      y = (d + j);
      if (x == (a + e) && y == (b + f)) {
        if (mp[make_pair(i, j)] == 0) arr.push_back(make_pair(i, j));
        mp[make_pair(i, j)] = 1;
      }
      x = (e + i);
      y = (f + j);
      if (x == (a + c) && y == (b + d)) {
        if (mp[make_pair(i, j)] == 0) arr.push_back(make_pair(i, j));
        mp[make_pair(i, j)] = 1;
      }
    }
  }
  cout << arr.size() << endl;
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i].first << " " << arr[i].second << endl;
  }
  return 0;
}
