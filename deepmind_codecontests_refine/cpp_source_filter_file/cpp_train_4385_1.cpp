#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  int diff;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  diff = abs(x - y);
  int s = diff * t1;
  diff += abs(x - z);
  int e = diff * t2 + 3 * t3;
  if (s < e)
    cout << "YES";
  else
    cout << "NO";
}
