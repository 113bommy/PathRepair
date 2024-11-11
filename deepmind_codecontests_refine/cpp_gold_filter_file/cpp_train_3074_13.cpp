#include <bits/stdc++.h>
using namespace std;
long long int getMax(long long int a, long long int b) {
  return (a > b ? a : b);
}
long long int getMin(long long int a, long long int b) {
  return (a < b ? a : b);
}
long long int getDig(long long int a) {
  long long int count = 0;
  while (a > 0) {
    count++;
    a >>= 1;
  }
  return count;
}
int main() {
  long long int i, temp, sum, x, sumdig, xdig, maxdig, carry = 0, ans = 1,
                                                       gotOnea = 0, gotOneb = 0;
  cin >> sum >> x;
  sumdig = getDig(sum), xdig = getDig(x);
  if (xdig > sumdig) {
    cout << 0;
    return 0;
  }
  maxdig = getMax(sumdig, xdig);
  for (i = maxdig - 1; i >= 0; i--) {
    temp = (1ll << i);
    if ((temp & x) > 0 && (temp & sum) > 0) {
      if (carry == 0)
        ans *= 2;
      else {
        cout << 0;
        return 0;
      }
    } else if ((temp & x) == 0 && (temp & sum) == 0) {
      if (carry == 1) {
        carry = 0;
        gotOnea = 1;
        gotOneb = 1;
      }
    } else if ((temp & x) == 0 && (temp & sum) > 0) {
      if (carry == 0)
        carry = 1;
      else {
        gotOnea = 1;
        gotOneb = 1;
      }
    } else {
      if (carry == 1)
        ans *= 2;
      else {
        cout << 0;
        return 0;
      }
    }
  }
  if (carry == 1)
    cout << 0;
  else {
    if (gotOnea == 0) ans -= 2;
    cout << ans << endl;
  }
  return 0;
}
