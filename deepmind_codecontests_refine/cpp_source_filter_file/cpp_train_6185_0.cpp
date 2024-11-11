#include <bits/stdc++.h>
using namespace std;
int GCD(int x, int y) {
  int mx, mn, w;
  mx = max(x, y);
  mn = min(x, y);
  w = mx % mn;
  if (w == 0) return mn;
  GCD(mn, w);
}
int n, A[110], gcd, res, MAX;
int main() {
  cin >> n;
  MAX = 0;
  for (int I = 0; I < n; ++I) {
    cin >> A[I];
    MAX = max(MAX, A[I]);
  }
  gcd = GCD(A[0], A[1]);
  for (int I = 2; I < n; ++I) {
    gcd = GCD(A[I], gcd);
    if (gcd == 1) break;
  }
  res = (MAX / gcd - n) % 2;
  if (res)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}
