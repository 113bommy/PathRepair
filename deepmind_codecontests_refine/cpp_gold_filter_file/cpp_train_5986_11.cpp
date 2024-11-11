#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n;
pair<int, int> pt[MAXN];
long double twoInv[111];
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> pt[i].first >> pt[i].second;
  }
  twoInv[0] = 1;
  for (int i = 1; i < 111; ++i) {
    twoInv[i] = twoInv[i - 1] * 0.5;
  }
  double C =
      (n < 1024 ? pow(2, n - 1) / (pow(2, n) - 1 - n - n * 1ll * (n - 1) / 2)
                : 0.5);
  double D = 1. / (pow(2, n) - 1 - n - n * 1ll * (n - 1) / 2);
  int k = min(100, n - 1);
  long double res = 0;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    res += (pt[i].first + pt[j].first) * 1ll * (pt[i].second - pt[j].second);
  }
  res = fabs(res) / 2;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    res -=
        gcd(abs(pt[i].first - pt[j].first), abs(pt[i].second - pt[j].second)) *
        0.5;
  }
  ++res;
  for (int i = 0; i < n; ++i) {
    long long area = (pt[i].first + pt[(i + 1) % n].first) * 1ll *
                     (pt[i].second - pt[(i + 1) % n].second);
    long long onBorder = gcd(abs(pt[i].first - pt[(i + 1) % n].first),
                             abs(pt[i].second - pt[(i + 1) % n].second));
    for (int j = 2; j < k; ++j) {
      int p = (i + j) % n;
      area += (pt[(p - 1 + n) % n].first + pt[p].first) * 1ll *
              (pt[(p - 1 + n) % n].second - pt[p].second);
      onBorder += gcd(abs(pt[(p - 1 + n) % n].first - pt[p].first),
                      abs(pt[(p - 1 + n) % n].second - pt[p].second));
      long double curArea = fabs(area + (pt[p].first + pt[i].first) * 1ll *
                                            (pt[p].second - pt[i].second)) *
                            0.5;
      int onSegment =
          gcd(abs(pt[i].first - pt[p].first), abs(pt[i].second - pt[p].second));
      long double curOnBorder = onBorder + onSegment;
      res -= (C * twoInv[j] - D) * (curArea - curOnBorder * 0.5 + onSegment);
    }
  }
  cout.precision(15);
  cout << fixed << showpoint;
  cout << res << '\n';
  return 0;
}
