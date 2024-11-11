#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  if (m >= n) {
    cout << n << endl;
    return 0;
  }
  long long int val = n - m - 1LL;
  long long int l = 1, r = 1e10;
  while (l <= r) {
    long long int mid = (l + r) / 2;
    long long int temp = mid * (mid + 1) / 2;
    if (temp > val)
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << (m + l) << endl;
  return 0;
}
