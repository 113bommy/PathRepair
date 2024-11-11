#include <bits/stdc++.h>
using namespace std;
int const INF = 100010;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long s, a, b, c;
    cin >> s >> a >> b >> c;
    long long ans = (s / (a * c)) * (a + b);
    ans += s % (a * c);
    cout << ans << endl;
  }
  return 0;
}
