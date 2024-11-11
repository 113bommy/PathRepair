#include <bits/stdc++.h>
using namespace std;
const int N = 3030;
long long n, ans, dex[N << 1];
long double val[N];
complex<long double> p[N];
void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    long double x, y;
    cin >> x >> y;
    p[i] = complex<long double>(x, y);
  }
}
char go(complex<long double> a, complex<long double> b,
        complex<long double> c) {
  complex<long double> u = b - a, v = c - a;
  long double x = u.real() * v.imag() - u.imag() * v.real();
  return (x > 0 ? 'L' : 'R');
}
void act(int x) {
  ans += (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
  iota(dex, dex + x, 0);
  iota(dex + x, dex + n - 1, x + 1);
  for (int i = 0; i < n - 1; i++) val[dex[i]] = arg(p[dex[i]] - p[x]);
  sort(dex, dex + n - 1, [](int a, int b) { return val[a] < val[b]; });
  copy(dex, dex + n - 1, dex + n - 1);
  long long r = 0;
  for (long long i = 0; i < n - 1; i++) {
    r = max(r, i);
    while ((r + 1 - i + 1) < n && dex[i] != dex[r + 1] &&
           go(p[dex[i]], p[dex[r + 1]], p[x]) == 'L')
      r++;
    ans -= (r - i) * (r - i - 1) * (r - i - 2) / 6;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  input();
  for (int i = 0; i < n; i++) act(i);
  cout << ans;
}
