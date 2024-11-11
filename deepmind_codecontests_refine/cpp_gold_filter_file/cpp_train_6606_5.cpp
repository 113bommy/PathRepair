#include <bits/stdc++.h>
using namespace std;
long long int f(long long int x) {
  long long int g = 1;
  while (x > 1) g *= x, x--;
  return g;
}
long long int per(long long int n, long long int r) {
  return (f(n)) / (f(n - r) * f(r));
}
void solve() {
  long long int n = 0, m = 0, u = 0;
  double k = 1;
  string s1, s2;
  cin >> s1 >> s2;
  for (long long int i = 0; i < s1.size(); i++) {
    if (s1[i] == '-')
      n--;
    else
      n++;
    if (s2[i] == '-')
      m--;
    else if (s2[i] == '?')
      u++, k *= ((double)1 / 2);
    else
      m++;
  }
  long long int p = (abs(m - n) + u) / 2;
  double ans = per(u, p) * k;
  if ((!u) && (m != n)) {
    cout << 0;
    return;
  }
  printf("%.9f", ans);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) solve();
  return 0;
}
