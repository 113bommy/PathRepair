#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long sum = 0;
  int p = n / 2;
  if (k >= p) {
    int r = n - 1;
    while (r) {
      sum += r;
      r--;
    }
    cout << sum;
    return 0;
  } else {
    long long mx = 0;
    int r = n - 1;
    int l = k;
    while (l > 0) {
      sum += r;
      r--;
      l--;
    }
    sum += (n - (2 * k)) * k;
    int y = (k - 1);
    sum += (y * (y + 1)) / 2;
    cout << sum;
  }
  return 0;
}
