#include <bits/stdc++.h>
using namespace std;
unsigned long long cnt1, cnt2, x, y;
bool check(unsigned long long a) {
  long long f1 = a / x, f2 = a / y, ff = a / (x * y);
  long long valid = a - f1 - f2 + ff;
  long long c1 = cnt1, c2 = cnt2;
  c1 = c1 - f2 + ff;
  c2 = c2 - f1 + ff;
  c1 = c1 < 0 ? 0 : c1;
  c2 = c2 < 0 ? 0 : c2;
  if ((c1 + c2) > valid) return false;
  return true;
}
int main() {
  cin >> cnt1 >> cnt2 >> x >> y;
  unsigned long long mid = -1, low = 0, high = 20;
  while (high - low > 1) {
    mid = (high + low) / 2;
    if (check(mid))
      high = mid;
    else
      low = mid;
  }
  cout << high << endl;
  return 0;
}
