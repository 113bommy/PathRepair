#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long str, intl, expo;
    cin >> str >> intl >> expo;
    long long low = 0, high = expo;
    long long mid = 0;
    while (low < high) {
      mid = (low + high) / 2;
      if (str + mid > (expo - mid) + intl &&
          str + mid - 1 <= (expo - mid + 1) + intl) {
        break;
      } else if (str + mid > (expo - mid) + intl) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    if (mid + str > intl) {
      cout << expo - mid + 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
