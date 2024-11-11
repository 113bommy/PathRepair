#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int ans = n, low = 1, high = n, mid = (low + high) / 2;
  while (low <= high) {
    mid = (low + high) / 2;
    long long int temp = mid, v = temp, kk = k;
    while (temp > 0) {
      temp /= k;
      kk *= k;
      v += temp;
    }
    if (v >= n)
      high = mid - 1, ans = min(ans, mid);
    else
      low = mid + 1;
  }
  cout << ans;
  return 0;
}
