#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  long long l = -1, r = n + 5;
  while (r - l > 1) {
    long long mid = (l + r) >> 1, p = n - mid, sum = (1 + p) * p / 2;
    if (sum - mid > k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << r << '\n';
}
