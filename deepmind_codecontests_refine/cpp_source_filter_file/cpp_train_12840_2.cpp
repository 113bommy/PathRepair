#include <bits/stdc++.h>
const int INF = (1 << 30);
const double EPS = 1.0e-6;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, ans = 0;
  long long s = 0LL;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    s += v[i];
  }
  if (v[0] * 2 == s) ans++;
  for (int i = 1; i < n - 1; i++) {
    v[i] += v[i - 1];
    if (v[i] * 2 == s) ans++;
  }
  cout << ans;
  return 0;
}
