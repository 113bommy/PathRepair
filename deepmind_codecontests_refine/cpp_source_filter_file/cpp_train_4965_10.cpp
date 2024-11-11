#include <bits/stdc++.h>
using namespace std;
long long int n;
bool yes(long long int k) {
  long long int c1 = 0;
  long long int n1 = n;
  while (n1 > 0) {
    c1 += min(k, n1);
    n1 -= min(k, n1);
    n1 -= n1 / 10;
  }
  return (2 * c1 > n);
}
long long int binarySearch(long long int l, long long int r) {
  if (r > l) {
    long long int mid = l + (r - l) / 2;
    if (yes(mid)) return binarySearch(l, mid);
    return binarySearch(mid + 1, r);
  } else if (r == l)
    return r;
}
int main() {
  cin >> n;
  long long int k = n / 10;
  if (k < 1) k = 1;
  bool ans = 1;
  long long int c1 = 0;
  long long int l = 1, r = k;
  cout << binarySearch(l, r) << endl;
}
