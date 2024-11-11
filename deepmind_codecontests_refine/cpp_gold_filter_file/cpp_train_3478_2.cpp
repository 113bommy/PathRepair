#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, j, n;
  vector<pair<int, int> > v;
  cin >> n;
  while (n--) {
    cin >> a;
    if (a)
      v.push_back(make_pair(a, v.size()));
    else {
      sort(v.begin(), v.end(), greater<pair<int, int> >());
      vector<int> temp(v.size(), -1);
      for (j = 0; j < 3 && j < v.size(); j++) temp[v[j].second] = j;
      for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == -1) {
          cout << "pushBack" << endl;
        }
        if (temp[i] == 0) {
          cout << "pushStack" << endl;
        }
        if (temp[i] == 1) {
          cout << "pushQueue" << endl;
        }
        if (temp[i] == 2) {
          cout << "pushFront" << endl;
        }
      }
      cout << j;
      if (j > 0) cout << " popStack";
      if (j > 1) cout << " popQueue";
      if (j > 2) cout << " popFront";
      cout << endl;
      v.clear();
    }
  }
  for (int i = 0; i < v.size(); i++) cout << "pushBack" << endl;
  return 0;
}
