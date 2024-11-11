#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  if (k1 > k2) {
    swap(a1, a2);
    swap(k1, k2);
  }
  int mn = max(0, n - (a1 * (k1 - 1) + a2 * (k2 - 1)));
  int mx = 0;
  if (n <= a1 * k1) {
    mx = n / k1;
  } else {
    mx = a1 + (n - (a1 * k1)) / k2;
  }
  cout << mn << " " << mx;
}
