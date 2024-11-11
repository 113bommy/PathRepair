#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n, k, i, total, maxi, div, q, sum, seq;
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  if (k > 141420) {
    cout << "-1" << endl;
    return 0;
  }
  div = ((k + 1) * k) / 2;
  if (div > n)
    cout << "-1" << endl;
  else if (div == n) {
    for (i = 1; i <= k; i++) cout << i << " ";
    cout << endl;
  } else {
    long long org, min_val, max = -1, ne;
    min_val = floor(sqrt(n));
    ne = n / div;
    div = min_val;
    for (i = 2; i <= min_val; i++) {
      if (n % i == 0) {
        if (i > max && i <= ne) max = i;
        if ((n / i) > max && (n / i) <= ne) max = n / i;
      }
    }
    div = max;
    sum = n / div;
    i = 1;
    total = 0;
    org = sum;
    while (sum) {
      sum -= i;
      seq = div * i;
      cout << (seq) << " ";
      total += i;
      i++;
      if (i == k) {
        cout << (div * (org - total)) << endl;
        break;
      }
    }
  }
  return 0;
}
