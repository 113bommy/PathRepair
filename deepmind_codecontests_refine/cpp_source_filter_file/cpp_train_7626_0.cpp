#include <bits/stdc++.h>
using namespace std;
void input() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  input();
  long long int t;
  cin >> t;
  while (t--) {
    long long int p, f, cnts, cntw, s, w;
    cin >> p >> f >> cnts >> cntw >> s >> w;
    long long int ans = 0;
    if (s > w) {
      swap(s, w);
      swap(cnts, cntw);
    }
    for (long long int i = 0; i <= cnts; i++) {
      if (i * s > p) break;
      long long int carry = min(cnts - i, f / s);
      ans = max(ans,
                i + carry + min((f - carry * s) / w + (p - i * s) / s, cntw));
    }
    cout << ans << endl;
  }
  return 0;
}
