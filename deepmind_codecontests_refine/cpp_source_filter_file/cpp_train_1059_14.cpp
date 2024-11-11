#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  long long int ct[21837];
  ct[1] = 1;
  for (int i = 2; i <= 21836; i++) {
    long long int digit = 0;
    long long int val = i;
    while (val) {
      val /= 10;
      digit++;
    }
    ct[i] = ct[i - 1] + digit;
  }
  while (q--) {
    long long int k;
    cin >> k;
    long long int previouscount = 0;
    long long int i = 1;
    for (i = 1; i <= 21836; i++) {
      previouscount += ct[i];
      if (previouscount > k) {
        previouscount -= ct[i];
        i--;
        break;
      }
    }
    k -= previouscount;
    if (k == 0) k = ct[i];
    for (long long int j = 1; j <= i; j++) {
      if (k == 0) break;
      int chk = 0;
      long long int digit = 0;
      long long int val = j;
      while (val) {
        val /= 10;
        digit++;
      }
      if (k > digit) {
        k -= digit;
      } else {
        k = digit - k + 1;
        int t = 1;
        while (j) {
          if (t == k) {
            cout << (j % 10) << endl;
            break;
          }
          j /= 10;
          t++;
        }
        k = 0;
      }
    }
  }
}
