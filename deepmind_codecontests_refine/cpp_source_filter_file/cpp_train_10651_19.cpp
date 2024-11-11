#include <bits/stdc++.h>
using namespace std;
int main() {
  int ma = -1, mp = -1, mc = -1;
  int taxi, girl, pizza;
  int n, c;
  string s, b;
  cin >> n;
  map<int, vector<string> > mp1, mp2, mp3;
  while (n--) {
    cin >> c >> s;
    taxi = 0, girl = 0, pizza = 0;
    while (c--) {
      cin >> b;
      if (b[0] == b[1] && b[1] == b[3] && b[3] == b[4] && b[4] == b[6] &&
          b[6] == b[7]) {
        taxi++;
      } else if (b[0] >= b[1] && b[1] > b[3] && b[3] > b[4] && b[4] > b[6] &&
                 b[6] > b[7]) {
        pizza++;
      } else {
        girl++;
      }
    }
    if (taxi > ma) ma = taxi;
    if (girl > mc) mc = girl;
    if (pizza > mp) mp = pizza;
    mp1[taxi].push_back(s);
    mp2[pizza].push_back(s);
    mp3[girl].push_back(s);
  }
  cout << "If you want to call a taxi, you should call: ";
  for (int i = 0; i < mp1[ma].size(); i++) {
    cout << mp1[ma][i];
    if (i == mp1[ma].size() - 1)
      cout << "." << endl;
    else
      cout << ",";
  }
  cout << "If you want to order a pizza, you should call: ";
  for (int i = 0; i < mp2[mp].size(); i++) {
    cout << mp2[mp][i];
    if (i == mp2[mp].size() - 1)
      cout << "." << endl;
    else
      cout << ",";
  }
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (int i = 0; i < mp3[mc].size(); i++) {
    cout << mp3[mc][i];
    if (i == mp3[mc].size() - 1)
      cout << "." << endl;
    else
      cout << ",";
  }
  return 0;
}
