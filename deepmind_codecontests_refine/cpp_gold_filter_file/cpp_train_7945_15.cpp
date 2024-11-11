#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  while (n--) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    bool b = false, p = false, c = false, r = false;
    for (int j = 0; j < v.size(); j++) {
      if ((v[i].first > v[j].first && v[i].second == v[j].second)) b = true;
      if ((v[i].first < v[j].first && v[i].second == v[j].second)) p = true;
      if ((v[i].first == v[j].first && v[i].second > v[j].second)) c = true;
      if ((v[i].first == v[j].first && v[i].second < v[j].second)) r = true;
    }
    if (b == true && p == true && c == true && r == true) {
      sum++;
      b = false;
      p = false;
      c = false;
      r = false;
    }
  }
  cout << sum << endl;
  return 0;
}
