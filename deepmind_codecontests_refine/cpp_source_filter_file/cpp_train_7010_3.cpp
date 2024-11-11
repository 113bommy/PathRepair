#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 0) {
    cout << "Impossible" << endl;
    return 0;
  }
  int mn, mx;
  mn = n;
  if (m == 0)
    mx = n;
  else
    mx = n + (m - 1);
  if (m > n) mn += (m - n);
  cout << mn << " " << mx << endl;
  return 0;
}
