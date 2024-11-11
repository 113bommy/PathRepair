#include <bits/stdc++.h>
using namespace std;
long long int good_number(long long int x);
int main() {
  long long int goodnum, mid, left = 1, right, i, j, q, n, number;
  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> n;
    left = 1;
    right = pow(10, 12);
    while (left <= right) {
      mid = (left + right) / 2;
      number = good_number(mid);
      if (number >= n) {
        goodnum = number;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    cout << goodnum << endl;
  }
}
long long int good_number(long long int n) {
  long long int multiplier = 1, ans = 0;
  while (n > 0) {
    ans += (n % 2) * multiplier;
    multiplier *= 3;
    n /= 2;
  }
  return ans;
}
