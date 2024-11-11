#include <bits/stdc++.h>
using namespace std;
const long long inff = 0x3f3f3f3f3f3f3f3f;
int n, a[200008], b[400008], c[200008], z, x, mx, y;
long long s = 0, qw = 0;
int sum(int x) {
  int s = 0;
  while (x > 0) {
    s += b[x];
    x -= x & (-x);
  }
  return s;
}
void add(int x, int y) {
  while (x <= 200000) {
    b[x] += y;
    x += x & (-x);
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i(1); i <= (n); ++i) scanf("%d", &a[i]), mx = max(mx, a[i]);
  sort(a + 1, a + n + 1);
  for (int i(1); i <= (n); ++i) add(a[i], 1);
  for (int i(1); i <= (n); ++i) {
    if (!c[a[i]]) {
      c[a[i]] = 1;
      z = a[i], qw = 0;
      while (z <= 200000) {
        y = sum(z + a[i] - 1) - sum(z - 1);
        qw += z * 1ll * y * 1ll;
        z += a[i];
      }
      s = max(s, qw);
    }
  }
  cout << s << endl;
  return 0;
}
