#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
bool isPrime(int x) {
  for (int i = 2; i <= sqrt(x); i++)
    if (x % i == 0) return 0;
  return 1;
}
int x[4] = {6, 8, 4, 2};
int main() {
  int n, t1, t2, k;
  cin >> n >> t1 >> t2 >> k;
  vector<pair<double, int>> res;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    double a = x * t1 - x * t1 * (k / 100.0) + y * t2,
           b = y * t1 - y * t1 * (k / 100.0) + x * t2;
    res.push_back(make_pair(max(a, b), double(i)));
  }
  sort(res.begin(), res.end());
  reverse(res.begin(), res.end());
  for (int i = 0; i < n;) {
    auto x = res[i];
    int l = i, r = i + 1;
    while (r < n && res[r].first == x.first) {
      r++;
    }
    for (int j = --r; j >= l; j--) {
      printf("%d %.2f\n", res[j].second + 1, res[j].first);
    }
    i = r + 1;
  }
  return 0;
}
