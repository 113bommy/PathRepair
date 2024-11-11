#include <bits/stdc++.h>
using namespace std;
long long a, b, al, ar, bl, br, ans;
int main() {
  cin >> a >> b;
  for (long long l = 1, p, r, g; l <= a + b; l = r + 1) {
    p = l, g = (a + b) / p, r = (a + b) / g;
    if (a < g || b < g) continue;
    al = (a + g) / (g + 1), ar = a / g;
    bl = (b + g) / (g + 1), br = b / g;
    if (al <= ar && bl <= br) ans += min(r, ar + br) - max(l, al + bl) + 1;
  }
  cout << ans << endl;
  return 0;
}
