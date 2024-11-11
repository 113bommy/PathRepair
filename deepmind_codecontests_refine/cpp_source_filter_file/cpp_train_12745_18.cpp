#include <bits/stdc++.h>
using namespace std;
long long int d[2009][2009];
int main() {
  int n, p, k, till;
  ios_base::sync_with_stdio(0);
  cin >> n >> p >> k;
  if (p - k >= 1) cout << "<< ";
  till = max(p - k, 1);
  while (till < p) {
    cout << till << " ";
    till++;
  }
  cout << "(" << p << ")"
       << " ";
  till = min(p + k, n);
  p++;
  while (p <= till) {
    cout << p << " ";
    p++;
  }
  if (till < n) cout << ">>";
  return 0;
}
