#include <bits/stdc++.h>
using namespace std;
int t, n;
long int testCase() {
  long long int x;
  cin >> x;
  long int result = 0;
  long long int nicecells = 1;
  long long int power = 0;
  while (true) {
    if (nicecells <= x) {
      result++;
      x -= nicecells;
    } else {
      break;
    }
    power++;
    nicecells = (pow(2, power) * pow(2, power)) + nicecells + nicecells;
  }
  return result;
}
signed main() {
  cin >> t;
  while (t-- > 0) {
    long int res = testCase();
    cout << res;
  }
  return 0;
}
