#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, z, s1 = 0, s2 = 0, s3 = 0, s4 = 0, k;
  cin >> x >> y >> z;
  s1 = x + y + z;
  s2 = (x + z) * 2;
  s3 = (x + y) * 2;
  s4 = (y + z) * 2;
  k = min(s1, s2);
  k = min(k, s3);
  k = min(k, s4);
  cout << k;
}
