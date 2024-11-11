#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  long long a = abs(x - y) * t1;
  long long b = abs(x - z) * t2 + abs(x - y) * t2 + t3 * 2;
  if (b <= a) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
