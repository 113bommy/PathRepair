#include <bits/stdc++.h>
using namespace std;
long long unsigned absolute(long long unsigned i, long long unsigned j) {
  if (i < j) swap(i, j);
  return i - j;
}
int main() {
  long long unsigned x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  cout << (absolute(x, y) * t1 >=
                   absolute(x, y) * t2 + absolute(x, z) * t2 + t3 * 2
               ? "YES"
               : "NO");
  return 0;
}
