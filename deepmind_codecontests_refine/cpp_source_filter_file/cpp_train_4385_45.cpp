#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  long long tl = 0, ts = 0;
  tl = abs(x - y) * t1;
  ts = 2 * t3 + (abs(x - z) + abs(x - y)) * t2;
  if (ts <= tl) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
