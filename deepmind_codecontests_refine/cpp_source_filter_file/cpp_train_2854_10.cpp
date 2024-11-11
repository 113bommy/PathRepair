#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  while (cin >> n) {
    long long int k = 0, val = 0, a1 = 0, a2 = 0, l = 2, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
      cin >> val;
      k++;
      if (k > 2) {
        if (a1 + a2 == val)
          l++;
        else
          l = 2, k = 1;
      }
      a1 = a2;
      a2 = val;
      mx = max(mx, l);
    }
    if (n == 1)
      cout << n << endl;
    else
      cout << mx << endl;
  }
  return 0;
}
