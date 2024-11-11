#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int main() {
  int x, y, a, b, i;
  cin >> x >> y >> a >> b;
  a++;
  while (a <= x) {
    int h = b;
    while (h <= y) {
      if (h < a) v.push_back(make_pair(a, h));
      h++;
    }
    a++;
  }
  cout << v.size() << endl;
  for (i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
  return 0;
}
