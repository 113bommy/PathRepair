#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << n;
  } else {
    long long int val = n - m;
    long long int l = 0;
    long long int r = 1e9;
    while (l < r) {
      long long int mid = (l + r) / 2;
      long long int val1 = (mid * (mid + 1)) / 2;
      if (val1 >= val) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << l + m;
  }
}
