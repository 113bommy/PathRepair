#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  string s;
  long long i, j;
  cin >> s;
  long long n = s.size();
  long long prefa[n + 1], prefb[n + 1];
  prefa[0] = 0, prefb[0] = 0;
  long long a = 0, b = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == 'a')
      a++;
    else if (s[i] == 'b')
      b++;
    prefa[i + 1] = a;
    prefb[i + 1] = b;
  }
  long long ans = -1e10;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      long long p = prefa[i] + (prefa[n] - prefa[j]) + (prefb[j] - prefb[i]);
      ans = max(ans, p);
    }
  }
  cout << ans << endl;
  return 0;
}
