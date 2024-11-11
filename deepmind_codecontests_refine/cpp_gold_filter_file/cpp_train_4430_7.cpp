#include <bits/stdc++.h>
using namespace std;
int v[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int sq[] = {0, 4, 9, 25, 49, 81};
int main() {
  ios::sync_with_stdio(false);
  string s;
  int ct = 1;
  for (int i = 1; i <= 15; ++i) {
    cout << v[i] << "\n";
    cout << flush;
    cin >> s;
    if (s == "yes" && ct == 2) {
      cout << "composite";
      cout << flush;
      return 0;
    } else if (s == "yes")
      ++ct;
  }
  for (int i = 1; i <= 5; ++i) {
    cout << sq[i] << "\n";
    cout << flush;
    cin >> s;
    if (s == "yes") {
      cout << "composite";
      cout << flush;
      return 0;
    }
  }
  cout << "prime";
  cout << flush;
  return 0;
}
