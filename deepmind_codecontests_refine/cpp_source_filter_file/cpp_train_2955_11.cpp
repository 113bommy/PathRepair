#include <bits/stdc++.h>
using namespace std;
int f[4];
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  set<pair<int, int> > s;
  int index = -1;
  s.insert(make_pair(v[0], 0));
  for (int i = 1; i + 1 < n; i++) {
    set<pair<int, int> >::iterator it = --s.end();
    if (it->first > v[i] && v[i] > v[i + 1]) {
      cout << 3 << endl;
      cout << it->second + 1 << " " << i + 1 << " " << i + 2;
      return 0;
    }
    it = s.begin();
    if (it->first < v[i] && v[i] < v[i + 1]) {
      cout << 3 << endl;
      cout << it->second + 1 << " " << i + 1 << " " << i + 2;
      return 0;
    }
    s.insert(make_pair(v[i], i));
  }
  cout << 0;
}
