#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  map<int, int> m;
  map<int, int> mm;
  int s = 0;
  while (x--) {
    int y, t;
    cin >> y >> t;
    m[y]++;
    mm[t]++;
    if (m[t] > 0) s += 1;
    if (mm[y] > 0) s += 1;
  }
  cout << s << "\n";
  return 0;
}
