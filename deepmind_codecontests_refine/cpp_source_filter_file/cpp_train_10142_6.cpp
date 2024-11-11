#include <bits/stdc++.h>
using namespace std;
;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, ac, bc, cc;
  ac = bc = cc = 0;
  cin >> a >> b;
  for (int i = 0; i < 6; i++) {
    if (abs(a - 1 - i) < abs(b - 1 - i))
      ac++;
    else {
      if (abs(a - i) == abs(b - i))
        cc++;
      else
        bc++;
    }
  }
  cout << ac << ' ' << cc << ' ' << bc << '\n';
  cout.flush();
}
