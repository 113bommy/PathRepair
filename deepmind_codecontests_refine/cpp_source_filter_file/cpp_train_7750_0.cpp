#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a >= b) return a;
  return b;
}
int main() {
  int n, m, i, j, k, l;
  cin >> n >> m;
  long long int ans = -1;
  vector<long long int> v(n);
  vector<long long int> s(n);
  for (i = 0; i < n; i++) {
    cin >> v[i] >> s[i];
    k = m;
    if (s[i] > 0) k++;
    if (v[i] <= k) {
      if (s[i] == 0)
        ans = max(ans, s[i]);
      else
        ans = max(ans, 100 - s[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}
