#include <bits/stdc++.h>
using namespace std;
template <class X>
X gcd(X a, X b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
template <class X>
X bs(X A[], X lo, X hi, X x) {
  if (hi >= lo) {
    X mid = (hi + lo) / 2;
    if (A[mid] == x)
      return mid;
    else if (A[mid] > x)
      return bs(A, lo, mid - 1, x);
    else
      return bs(A, mid + 1, hi, x);
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (n % 2 == 0)
    cout << a[n / 2 - 1] << endl;
  else
    cout << a[n / 2] << endl;
  return 0;
}
