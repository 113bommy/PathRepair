#include <bits/stdc++.h>
using namespace std;
const int N = 3001;
const long long MOD = 1000000007;
const long long S = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int x, p;
  cout << "? " << 1 << " " << 1 << endl;
  cin >> x;
  int l = 2, r = S - 1;
  int x1, x2, y1, y2;
  while (l <= r) {
    int m = (l + r) / 2;
    cout << "? " << m << " " << 1 << endl;
    cin >> p;
    if ((x - m + 1) != p)
      r = m - 1;
    else {
      x1 = m;
      l = m + 1;
    }
  }
  cout << "? " << x1 << " " << 1 << endl;
  cin >> y1;
  y1++;
  cout << "? " << S << " " << 1 << endl;
  cin >> x;
  x2 = S - (x - y1 + 1);
  cout << "? " << 1 << " " << S << endl;
  cin >> x;
  y2 = S - (x - x1 + 1);
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << endl;
  return 0;
}
