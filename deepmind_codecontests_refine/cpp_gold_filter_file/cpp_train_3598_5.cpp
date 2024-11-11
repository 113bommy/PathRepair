#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<int> vx, vm;
    for (int i = 1; i <= n; i += 2) {
      if (i == n) {
        vx.push_back(i);
        vm.push_back(i);
      } else {
        cout << '?' << ' ' << i << ' ' << i + 1 << '\n';
        fflush(stdout);
        char q;
        cin >> q;
        if (q == '<') {
          vm.push_back(i);
          vx.push_back(i + 1);
        } else {
          vx.push_back(i);
          vm.push_back(i + 1);
        }
      }
    }
    int px = vx[0];
    for (int i = 1; i < vx.size(); ++i) {
      cout << '?' << ' ' << px << ' ' << vx[i] << '\n';
      fflush(stdout);
      char q;
      cin >> q;
      if (q == '<') px = vx[i];
    }
    int pm = vm[0];
    for (int i = 1; i < vm.size(); ++i) {
      cout << '?' << ' ' << pm << ' ' << vm[i] << '\n';
      fflush(stdout);
      char q;
      cin >> q;
      if (q == '>') pm = vm[i];
    }
    cout << '!' << ' ' << pm << ' ' << px << '\n';
    fflush(stdout);
  }
}
