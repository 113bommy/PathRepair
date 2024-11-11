#include <bits/stdc++.h>
using namespace std;
int even = 0, odd = 0, n, k;
int f() {
  if (n == k) return odd % 2;
  int s = (n - k) / 2;
  if ((n - k) % 2) {
    if (k & 1)
      return odd > s;
    else
      return odd > s && even > s;
  } else {
    if (k & 1)
      return even <= s;
    else
      return 0;
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (x & 1)
      odd++;
    else
      even++;
  }
  cout << (f() ? "Stannis" : "Daenerys") << endl;
  return 0;
}
