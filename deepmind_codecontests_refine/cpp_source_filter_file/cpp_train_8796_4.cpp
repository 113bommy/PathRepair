#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const long double oo = 1e8;
const long double eps = 1e-10;
int n;
long long r, v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> r >> v;
  cout << fixed << setprecision(6);
  for (int i = 1; i <= n; i++) {
    long long s, f;
    cin >> s >> f;
    long long d = f - s;
    if (r > d * oo && r > v * oo) {
      puts("0.5");
      continue;
    }
    long double l = 0, h = 1.0 * d / r, ans = 0;
    while (h - l > eps) {
      long double mid = (l + h) / 2;
      long double check = (sqrt(2 - 2 * cos(mid)) + mid) * r;
      if (check > (long double)d)
        ans = mid, h = mid;
      else
        l = mid;
    }
    cout << (double)(ans / v * r) << "\n";
  }
  return 0;
}
