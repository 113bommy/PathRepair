#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, k, i;
  cin >> n >> p >> k;
  if ((p - k) > 0) cout << "<< ";
  int m = (p + k < n ? p + k : n);
  int t = (p - k > 0 ? p - k : 0);
  for (i = t; i <= m; i++) {
    if (i == p) {
      cout << "(" << p << ") ";
      continue;
    }
    cout << i << " ";
  }
  if (n - p > k) cout << ">>";
}
