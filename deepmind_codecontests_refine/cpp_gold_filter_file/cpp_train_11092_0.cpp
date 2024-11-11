#include <bits/stdc++.h>
using namespace std;
int n, r, dist;
string dir;
int main() {
  dist = 1000000001;
  r = -1;
  cin >> n;
  cin >> dir;
  for (int i = 0; i < n; i++) {
    int coord;
    cin >> coord;
    if (dir[i] == 'R') {
      r = coord;
    } else {
      if ((coord - r < dist) && (r != -1)) {
        dist = coord - r;
      }
    }
  }
  if (dist == 1000000001) {
    cout << "-1";
  } else {
    cout << (dist / 2);
  }
  return 0;
}
