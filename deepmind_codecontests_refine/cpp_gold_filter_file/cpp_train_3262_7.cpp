#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, s, mn = 0, d, f = 0, i, j;
  double dp;
  vector<long long> ve, ne;
  cin >> a >> s;
  for (i = 0; i < a; i++) {
    cin >> d;
    ve.push_back(d);
    mn = max(mn, d);
  }
  for (i = 0; i < a; i++) {
    ne.push_back(mn - ve[i]);
    f += mn - ve[i];
  }
  if (f > s) {
    cout << -1;
    return 0;
  }
  cout << fixed << setprecision(6);
  for (i = 0; i < a; i++) {
    cout << (s - f + 0.0) / a + ne[i] << endl;
  }
  return 0;
}
