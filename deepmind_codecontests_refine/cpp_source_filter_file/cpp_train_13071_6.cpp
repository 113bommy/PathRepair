#include <bits/stdc++.h>
using namespace std;
const long long inff = 0x3f3f3f3f3f3f3f3f;
int n, a[200008], b[200008], c[200008], sum[200008], z, x, y;
long long s = 0, qw = 0;
int main() {
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i(1); i <= (n); ++i) scanf("%d", &a[i]), b[a[i]]++;
  for (int i(1); i <= (200000); ++i) sum[i] = sum[i - 1] + b[i];
  for (int i(1); i <= (n); ++i) {
    if (!c[a[i]]) {
      c[a[i]] = 1;
      z = a[i], qw = 0;
      while (z <= 200000) {
        y = sum[z + a[i] - 1] - sum[z - 1];
        qw += z * 1ll * y * 1ll;
        z += a[i];
      }
      s = max(s, qw);
    }
  }
  cout << s << endl;
  return 0;
}
