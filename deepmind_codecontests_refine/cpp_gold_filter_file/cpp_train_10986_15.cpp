#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int res = 0;
  for (long long int i = 0; i < n; i++) {
    long long int j = i + 1;
    long long int k = i - 1;
    long long int prev1 = a[i];
    long long int prev2 = a[i];
    long long int c = 0;
    long long int d = 0;
    while (j < n) {
      if (a[j] <= prev1) {
        c++;
        prev1 = a[j];
      } else {
        break;
      }
      j++;
    }
    while (k >= 0) {
      if (a[k] <= prev2) {
        d++;
        prev2 = a[k];
      } else {
        break;
      }
      k--;
    }
    long long int q = c + d + 1;
    res = max(res, q);
  }
  cout << res;
}
