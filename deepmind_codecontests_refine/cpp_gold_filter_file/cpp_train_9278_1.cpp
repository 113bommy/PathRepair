#include <bits/stdc++.h>
using namespace std;
int n;
bool check(int m) {
  long long v = (m - 1) / 2;
  if ((v + 1) * (m - v + 1) >= n || (v + 2) * (m - v) >= n)
    return true;
  else
    return false;
}
void xuly() {
  int t;
  t = 1;
  while (t--) {
    cin >> n;
    int p = ceil(sqrt(n)), q = floor(sqrt(n));
    if (p * q >= n)
      cout << p + q << endl;
    else
      cout << p + p << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  xuly();
}
