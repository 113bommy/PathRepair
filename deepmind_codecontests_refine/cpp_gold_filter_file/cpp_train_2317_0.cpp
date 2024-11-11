#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ev, od;
    int eve = 0, ode = 0;
    for (int i = 0; i < 2 * n; i++) {
      int k;
      cin >> k;
      if (k % 2 == 0) {
        eve++;
        ev.push_back(i);
      } else {
        ode++;
        od.push_back(i);
      }
    }
    if (eve % 2 == 0) {
      if (ode == 0) {
        for (int i = 2; i < eve - 1; i = i + 2) {
          cout << ev[i] + 1 << " " << ev[i + 1] + 1 << endl;
        }
      } else if (eve == 0) {
        for (int i = 2; i < ode - 1; i = i + 2) {
          cout << od[i] + 1 << " " << od[i + 1] + 1 << endl;
        }
      } else {
        for (int i = 0; i < eve - 1; i = i + 2) {
          cout << ev[i] + 1 << " " << ev[i + 1] + 1 << endl;
        }
        for (int i = 2; i < ode - 1; i = i + 2) {
          cout << od[i] + 1 << " " << od[i + 1] + 1 << endl;
        }
      }
    } else {
      for (int i = 1; i < eve - 1; i = i + 2) {
        cout << ev[i] + 1 << " " << ev[i + 1] + 1 << endl;
      }
      for (int i = 1; i < ode - 1; i = i + 2) {
        cout << od[i] + 1 << " " << od[i + 1] + 1 << endl;
      }
    }
  }
  return 0;
}
