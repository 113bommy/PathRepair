#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int l = 1, r = n, res = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (n / mid == 1) {
      res = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << res;
  return 0;
}
