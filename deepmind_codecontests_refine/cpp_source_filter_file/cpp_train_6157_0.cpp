#include <bits/stdc++.h>
using namespace std;
long long first, second, x2, y2;
long long n;
char a[100010];
long long col[1010];
long long chi[100][100010];
long long ans = 0;
long long tx[100010], ty[100010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> first >> second;
  cin >> x2 >> y2;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  long long dx = x2 - first, dy = y2 - second;
  long long lx = 0, ly = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 'L') --lx;
    if (a[i] == 'R') ++lx;
    if (a[i] == 'U') ++ly;
    if (a[i] == 'D') --ly;
    tx[i] = lx;
    ty[i] = ly;
  }
  long long l = 0, r = 1e18;
  while (r - l > 1) {
    long long m = (r + l) / 2;
    long long k = m / n;
    if (abs(dx - tx[n] * k - tx[m % n]) + abs(dy - ty[n] * k - ty[m % n]) > m) {
      l = m;
    } else {
      r = m;
    }
  }
  long long m = l;
  long long k = m / n;
  if (abs(dx - tx[n] * k - tx[m % n]) + abs(dy - ty[n] * k - ty[m % n]) > m) {
    m = r;
    int k = m / n;
    if (abs(dx - tx[n] * k - tx[m % n]) + abs(dy - ty[n] * k - ty[m % n]) > m) {
      cout << -1;
    } else {
      cout << r;
    }
  } else {
    cout << l;
  }
  return 0;
}
