#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  string str;
  cin >> str;
  fflush(stdout);
  while (str == "start") {
    int l = 0, r = 1;
    while (r < 1000000007) {
      cout << "? " << l << " " << r << endl;
      fflush(stdout);
      string aw;
      cin >> aw;
      fflush(stdout);
      if (aw == "e") {
        return 0;
      } else if (aw == "x") {
        break;
      } else {
        if (l == 0) {
          l = 1;
        } else {
          l <<= 1;
        }
        r <<= 1;
      }
    }
    while (l < r) {
      if (r - l == 1) {
        cout << "? " << l << " " << r << endl;
        fflush(stdout);
        string aw;
        cin >> aw;
        fflush(stdout);
        if (aw == "e") {
          return 0;
        } else if (aw == "x") {
          l = r;
        } else {
          r = l;
        }
        break;
      }
      cout << "? " << l << " " << (l + r) / 2 << endl;
      fflush(stdout);
      string aw;
      cin >> aw;
      fflush(stdout);
      if (aw == "e") {
        return 0;
      } else if (aw == "x") {
        r = (l + r) / 2;
      } else {
        l = (l + r) / 2;
      }
    }
    cout << "! " << l << endl;
    fflush(stdout);
    cin >> str;
    fflush(stdout);
  }
  return 0;
}
