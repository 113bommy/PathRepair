#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, pair<int, int> > doit(char amu[]) {
  pair<pair<int, int>, pair<int, int> > res;
  res.first.first = 7;
  for (int mi = 0; mi < 4; mi++) {
    pair<int, int> up;
    pair<int, int> down;
    up.first = amu[mi];
    up.second = amu[(mi + 1) % 4];
    down.first = amu[(mi + 2) % 4];
    down.second = amu[(mi + 3) % 4];
    res = min(res, make_pair(up, down));
  }
  return res;
}
int main() {
  set<pair<pair<int, int>, pair<int, int> > > s;
  int n;
  cin >> n;
  char amu[4];
  cin >> amu[0] >> amu[1] >> amu[3] >> amu[2];
  s.insert(doit(amu));
  for (int i = 1; i < n; i++) {
    string st;
    cin >> st;
    cin >> amu[0] >> amu[1] >> amu[3] >> amu[2];
    s.insert(doit(amu));
  }
  cout << s.size() << endl;
  return 0;
}
