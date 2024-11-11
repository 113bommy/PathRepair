#include <bits/stdc++.h>
using namespace std;
long long x;
long long nedge(long long m) { return x - m + min((m * (m - 1)) / 2, x - m); }
long long ts(long long low, long long high) {
  long long m1, m2;
  long long ne1, ne2, nel = -1;
  while (high > low) {
    m1 = low + (high - low) / 3;
    m2 = high - (high - low) / 3;
    ne1 = nedge(m1);
    ne2 = nedge(m2);
    if (ne2 < ne1)
      high = m2 - 1;
    else if (ne1 < ne2)
      low = m1 + 1;
    else
      low = m1 + 1, high = m2 - 1;
    if (nel < ne1) nel = ne1;
    if (nel < ne2) nel = ne2;
  }
  return nel;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> x;
    cout << ts(1, x + 1) << endl;
  }
  return 0;
}
