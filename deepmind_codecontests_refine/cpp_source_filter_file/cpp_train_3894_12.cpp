#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int r, g, b;
    cin >> r >> g >> b;
    int minim = min(r, min(g, b));
    int ans = minim;
    for (int i = 0; i < 3 && i < minim; i++) {
      int curr = minim - i;
      int currans = curr;
      currans += (r - curr) / 3;
      currans += (g - curr) / 3;
      currans += (b - curr) / 3;
      ans = max(ans, currans);
    }
    cout << ans << endl;
  }
  return 0;
}
