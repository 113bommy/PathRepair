#include <bits/stdc++.h>
using namespace std;
inline long long int s(long long int k) { return k * (k + 1) / 2; }
int main() {
  long long int n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (n <= k) {
    cout << 1 << endl;
    return 0;
  }
  n--;
  k--;
  long long int all = s(k);
  if (all < n) {
    cout << -1 << endl;
    return 0;
  }
  long long int low = 1, high = k, mid = 0;
  while (low < high) {
    mid = low + (high - low) / 2;
    long long int val = all - s(mid - 1);
    if (val == n) {
      cout << (k - mid + 1) << endl;
      return 0;
    }
    if (val > n) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  cout << (k - low + 2) << endl;
  return 0;
}
