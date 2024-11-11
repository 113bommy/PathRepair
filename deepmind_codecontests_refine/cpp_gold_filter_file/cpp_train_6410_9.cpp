#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
long long k;
long long f(int tx, int ty) {
  long long T = n == 1 ? m : (2 * n - 2) * m;
  long long div = k / T;
  long long rest = k % T;
  if (tx == 1) return (rest >= ty) ? div + 1 : div;
  if (tx == n) return (rest - (n - 1) * m >= ty) ? div + 1 : div;
  if (rest <= m * n) {
    long long ord = (tx - 1) * m + ty;
    return rest >= ord ? div * 2 + 1 : div * 2;
  } else {
    rest -= (n - 1) * m;
    long long ord = (n - tx) * m + ty;
    return rest >= ord ? div * 2 + 2 : div * 2 + 1;
  }
}
int main() {
  cin >> n >> m >> k >> x >> y;
  long long a = f(1, 1), b = n >= 2 ? f(2, 1) : 0, c = n >= 2 ? f(n - 1, 1) : 0;
  cout << max(max(a, b), c) << " " << f(n, m) << " " << f(x, y) << endl;
  return 0;
}
