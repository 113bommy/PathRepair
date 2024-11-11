#include <bits/stdc++.h>
using namespace std;
long long tests;
long long a, b, c, d, e, n, m, k;
void solve() {
  cin >> c >> d >> n >> m >> k;
  a = n * m;
  a -= k;
  if (a <= 0) {
    cout << 0;
    return;
  }
  e = d * n;
  if (c >= e) {
    cout << d * a;
    return;
  }
  e = (a / n) * c;
  a %= n;
  if (c < d * a)
    cout << e + c;
  else
    cout << e + (d * a);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
}
