#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  long long int a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  long long int v[4];
  v[0] = a + b;
  v[1] = b + d;
  v[2] = d + c;
  v[3] = c + a;
  long long int mn = 1e7, mx = 0;
  for (auto i = 0; i < 4; i++) {
    mx = max(v[i], mx);
    mn = min(v[i], mn);
  }
  if (mn + n - mx > 0)
    cout << n * (n + mn - mx) << endl;
  else
    cout << 0 << endl;
  return 0;
}
