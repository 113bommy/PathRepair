#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  int n, m, x1, y1, x2, y2, v1, v2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  v1 = abs(x1 - x2);
  v2 = abs(y1 - y2);
  if (v1 <= 4 && v2 <= 4 && (!(v1 == 3 && v2 == 4)) &&
      (!(v1 == 4 && v2 == 4)) && (!(v1 == 4 && v2 == 3)))
    cout << "First";
  else
    cout << "Second";
  return 0;
}
