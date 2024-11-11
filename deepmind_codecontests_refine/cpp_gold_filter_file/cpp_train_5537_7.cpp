#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  int mn = n - ((a1 * (k1 - 1)) + (a2 * (k2 - 1)));
  if (mn < 0) mn = 0;
  if (mn > n) mn = n;
  cout << mn;
  int mx = 0;
  if (k1 > k2) swap(k1, k2), swap(a1, a2);
  while (a1-- && n >= k1) {
    n -= k1;
    mx++;
  }
  while (a2-- && n >= k2) {
    n -= k2;
    mx++;
  }
  cout << " " << mx;
}
