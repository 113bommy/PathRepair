#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int h, m;
    cin >> h >> m;
    int hh = 23 - h;
    int mm = 60 - m;
    int tt = mm + (hh * 60);
    cout << tt << endl;
  }
  return 0;
}
