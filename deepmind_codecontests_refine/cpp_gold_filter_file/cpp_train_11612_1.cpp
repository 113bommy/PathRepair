#include <bits/stdc++.h>
using namespace std;
void sample() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sample();
  long long int t = 1, n, m, q, k, x, y, p, w, i, j, count = 1, sum = 0, ans,
                mod = 1000000007, b;
  while (t--) {
    long long int h1, h2, a, b;
    cin >> h1 >> h2 >> a >> b;
    if (h2 - h1 <= 8 * a) {
      cout << 0 << endl;
    } else if (b >= a) {
      cout << -1 << endl;
    } else {
      x = h2 - h1 - 8 * a;
      y = 12 * (a - b);
      long double r = x / (long double)y;
      n = ceil(r);
      cout << n << endl;
    }
  }
}
