#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int lest = abs(x - y) * t1;
  int lift = abs(z - x) * t1 + t3 + t3 + t3 + abs(x - y) * t2;
  if (lest < lift) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}
