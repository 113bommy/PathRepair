#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (n == k) {
    cout << 1 << endl;
    return 0;
  }
  long long o = 1, e = 2;
  long long om = o, em = 2;
  if (n % 2 == 0) em = 1;
  while (n && e < k) {
    n /= 2;
    if (n % 2 == 0) {
      om = e + 1;
      em = em + o + 1;
    } else {
      om = em + 1;
      em = e + om + 1;
    }
    o = e + 1;
    e = e + o + 1;
  }
  long long ans = 0;
  if (n % 2 == 0) {
    if (k <= em)
      ans = n;
    else if (k <= om)
      ans = n - 1;
    else if (k <= e)
      ans = n - 2;
  } else {
    if (k <= om)
      ans = n;
    else if (k <= em)
      ans = n - 1;
    else if (k <= o)
      ans = n - 2;
    else
      ans = n - 3;
  }
  cout << ans << endl;
  return 0;
}
