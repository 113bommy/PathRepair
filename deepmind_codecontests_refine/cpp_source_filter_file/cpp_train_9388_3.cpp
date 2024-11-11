#include <bits/stdc++.h>
const int MAXN = 1e6 + 20;
const int MAXNk = 1e4 + 20;
using namespace std;
const long long INF = 1e16;
int t, n;
long long ans, k, x, maxx;
long long d[20000], h[20000];
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t > 0) {
    t--;
    cin >> n >> x;
    ans = 2000000000000000000;
    maxx = 0;
    for (int i = 1; i <= n; i++) {
      cin >> d[i] >> h[i];
      if (d[i] > maxx) maxx = d[i];
    }
    for (int i = 1; i <= n; i++) {
      if (d[i] <= h[i]) continue;
      k = (x - maxx) / (d[i] - h[i]);
      if ((x - maxx) % (d[i] - h[i]) != 0) k++;
      k++;
      ans = min(ans, k);
      if (ans < 0) ans = 0;
    }
    if (maxx >= x)
      cout << 0 << endl;
    else if (ans == 2000000000000000000)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}
