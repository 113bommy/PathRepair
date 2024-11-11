#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int p, f;
    cin >> p >> f;
    if (f > p) swap(f, p);
    int cnts, cntw;
    cin >> cnts >> cntw;
    int s, w;
    cin >> s >> w;
    int ans = 0;
    if (s > w) swap(s, w), swap(cnts, cntw);
    for (int i = 1; i <= min(cnts, p / s); i++) {
      int curAns = 0, a = p, b = f, c = cnts, d = cntw;
      curAns += i;
      c -= i, a -= (s * i);
      int wused = min(d, (a / w));
      d -= wused, curAns += wused;
      int used = min(c, b / s);
      c -= used, curAns += used, b -= (used * s);
      used = min(d, b / w);
      curAns += used;
      ans = max(ans, curAns);
    }
    cout << ans << "\n";
  }
  return 0;
}
