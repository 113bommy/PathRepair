#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> x;
  set<int> y;
  set<pair<int, int> > ss;
  for (int(i) = 0; (i) < (8); ++(i)) {
    int xx, yy;
    cin >> xx >> yy;
    x.insert(xx);
    y.insert(yy);
    ss.insert(make_pair(xx, yy));
  }
  if ((int)(x).size() != 3 || (int)(y).size() != 3) {
    cout << "ugly" << endl;
    return 0;
  }
  vector<int> vx;
  vector<int> vy;
  for (typeof((x).begin()) it = (x).begin(); (it) != (x).end(); ++(it))
    vx.push_back(*it);
  for (typeof((y).begin()) it = (y).begin(); (it) != (y).end(); ++(it))
    vy.push_back(*it);
  set<int>::iterator itt = y.begin();
  int cc = 1;
  for (int(i) = 0; (i) < (3); ++(i)) {
    for (int(j) = 0; (j) < (3); ++(j)) {
      if (i == 1 && j == 1) {
        if (ss.find(make_pair(vx[i], vy[j])) != ss.end()) {
          cout << "ugly" << endl;
          return 0;
        }
      } else {
        if (ss.find(make_pair(vx[i], vy[j])) == ss.end()) {
          cout << "ugly" << endl;
          return 0;
        }
      }
    }
  }
  cout << "respectable" << endl;
  return 0;
}
