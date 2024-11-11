#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, countZ = 0, countM = 0, count = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a == 0) {
      ++countZ;
    } else if (a > 0) {
      count += a - 1;
    } else {
      count += -a - 1;
      countM++;
    }
  }
  count += countZ;
  if ((countM & 1) == 1) {
    if (countZ == 0) {
      count += 2;
    }
  }
  cout << count;
  return 0;
}
