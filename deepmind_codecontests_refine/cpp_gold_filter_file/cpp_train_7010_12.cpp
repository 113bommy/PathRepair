#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 0 && m > 0) {
    cout << "Impossible" << endl;
    return 0;
  }
  int mn, mx;
  mn = n + (max(0, m - n));
  mx = n + max(0, m - 1);
  cout << mn << " " << mx << endl;
  return 0;
}
