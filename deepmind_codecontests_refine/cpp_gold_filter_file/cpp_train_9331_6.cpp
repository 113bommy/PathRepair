#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A, B;
  long long x, y, z;
  cin >> A >> B;
  cin >> x >> y >> z;
  A -= 2 * x;
  A -= y;
  B -= y;
  B -= 3 * z;
  long long ans = 0;
  if (A < 0) {
    ans -= A;
  }
  if (B < 0) {
    ans -= B;
  }
  cout << ans << endl;
  return 0;
}
