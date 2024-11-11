#include <bits/stdc++.h>
using namespace std;
int handing(int m, int k) {
  if (m >= k) {
    int s = m / k;
    m /= k;
    return s + handing(m, k);
  } else {
    return 0;
  }
}
int loop(int n, int k, int m) {
  int l = 1, r = n;
  int q;
  int mid = (r + l) / 2;
  while (mid != l && mid != r) {
    q = handing(mid, k) + mid;
    if (q < m) {
      l = mid;
    } else if (q > m) {
      r = mid;
    } else
      return mid;
    mid = (r + l) / 2;
  }
  for (int i = l; i <= r; i++) {
    q = handing(i, k) + mid;
    if (q >= m) {
      return i;
    }
  }
  return 0;
}
int main() {
  long n, k;
  cin >> n >> k;
  cout << loop(n, k, n);
}
