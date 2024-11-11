#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 19;
const int LOGN = 4;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int I = 0; I < t; I++) {
    int c, d;
    cin >> c >> d;
    if ((c + d) % 2 == 1)
      cout << -1 << '\n';
    else if (c == d) {
      if (c == 0)
        cout << 0 << '\n';
      else
        cout << 1 << '\n';
    } else
      cout << 2 << '\n';
  }
}
