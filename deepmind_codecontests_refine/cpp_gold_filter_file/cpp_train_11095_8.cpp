#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x1, y1, x2, y2, i;
  cin >> n;
  cout << "YES\n";
  for (i = 0; i < n; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 & 1 && y1 & 1)
      cout << "1";
    else if (!(x1 & 1) && y1 & 1)
      cout << "2";
    else if (x1 & 1 && !(y1 & 1))
      cout << "3";
    else
      cout << "4";
    cout << "\n";
  }
  return 0;
}
