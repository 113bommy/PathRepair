#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > guestList;
int main() {
  int n;
  cin >> n;
  int it = 3;
  int c = 3;
  if (n == 1) {
    cout << "2\n";
    vector<int> tmp;
    tmp.push_back(1);
    guestList.push_back(tmp);
    guestList.push_back(tmp);
  } else if (n == 2) {
    cout << "2\n";
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    guestList.push_back(tmp);
    guestList.push_back(tmp);
  } else {
    vector<int> tmp;
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(2);
    guestList.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(3);
    guestList.push_back(tmp);
    tmp.clear();
    tmp.push_back(2);
    tmp.push_back(3);
    guestList.push_back(tmp);
    while (n >= (c + it)) {
      int slize = c + 1;
      int slizeori = c + 1;
      for (int i = 0; i < it; i++) {
        guestList[i].push_back(slize);
        slize++;
      }
      c += it;
      it++;
      tmp.clear();
      for (int i = slizeori; i < slize; i++) {
        tmp.push_back(i);
      }
      guestList.push_back(tmp);
    }
    cout << it << "\n";
  }
  for (int i = 0; i < guestList.size(); i++) {
    sort(guestList[i].begin(), guestList[i].end());
    for (int j = 0; j < guestList[i].size(); j++) {
      cout << guestList[i][j];
      if (j != (guestList[i].size() - 1)) cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
