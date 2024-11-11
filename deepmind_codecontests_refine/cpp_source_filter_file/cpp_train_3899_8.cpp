#include <bits/stdc++.h>
using namespace std;
int n, v, d[3030], maxA, ans = 0;
int main() {
  cin >> n >> v;
  for (int a, b, i = 1; i <= n; i++) {
    cin >> a >> b;
    d[a] = b;
    maxA = max(a, maxA);
  }
  ans += min(d[1], v);
  d[1] -= ans;
  for (int i = 2; i <= maxA; i++) {
    int t = v - min(v, d[i - 1]);
    ans += min(v, d[i - 1]);
    d[i - 1] -= min(v, d[i - 1]);
    int x = min(t, d[i]);
    ans += x;
    d[i] -= x;
  }
  ans += d[maxA];
  cout << ans << endl;
  return 0;
}
