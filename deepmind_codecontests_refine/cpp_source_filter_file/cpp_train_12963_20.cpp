#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > evs;
int main() {
  int n;
  cin >> n;
  ;
  for (int i(0); i < n; i++) {
    string s;
    cin >> s;
    pair<int, int> bii, eii;
    cin >> bii.first >> eii.first;
    if (s == "M") {
      bii.second = 0;
      eii.second = 2;
    } else {
      bii.second = 1;
      eii.second = 3;
    }
    evs.push_back(bii);
    evs.push_back(eii);
  }
  sort(evs.begin(), evs.end());
  int mcnt = 0, fcnt = 0, mx = 0;
  for (auto i : evs) {
    switch (i.second) {
      case 0:
        mcnt++;
        break;
      case 1:
        fcnt++;
        break;
      case 2:
        mcnt--;
        break;
      case 3:
        fcnt++;
        break;
    }
    mx = max(mx, min(fcnt, mcnt));
  }
  cout << mx * 2 << endl;
  return 0;
}
