#include <bits/stdc++.h>
using namespace std;
vector<long long> a, b;
long long test(long long x) {
  long long ans = 0;
  for (int i = 0; i < a.size(); i++) {
    ans += a[i] * x / b[i] + 1;
  }
  return ans;
}
int main() {
  int n, c;
  cin >> n >> c;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  int x = 0;
  int ans = 0;
  while (1) {
    int t = test(x);
    if (t == c) ans++;
    if (t > c) break;
    x++;
    if (x > 1000000) {
      if (ans)
        cout << -1 << endl;
      else
        cout << 0 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
