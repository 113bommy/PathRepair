#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
double dis(long u, long v, long p, long q) {
  return sqrt(((double)u - p) * (u - p) + ((double)q - v) * (q - v));
}
struct point {
  int x;
  int y;
};
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 0) {
    cout << 0 << " " << 1 << endl;
    cout << 0 << " " << m << endl;
    cout << 0 << " " << 0 << endl;
    cout << 0 << " " << m - 1 << endl;
    return 0;
  }
  if (m == 0) {
    cout << 1 << " " << 0 << endl;
    cout << n << " " << 0 << endl;
    cout << 0 << " " << 0 << endl;
    cout << n - 1 << " " << 0 << endl;
    return 0;
  }
  double tam1 = 2 * dis(0, 0, n - 1, m);
  double tam2 = 2 * dis(0, 0, n, m - 1);
  double tam3 = sqrt(double(m) * m + double(n) * n) + max(m, n);
  if (tam3 >= tam1 && tam3 >= tam2) {
    cout << 0 << " " << 0 << endl;
    cout << n << " " << m << endl;
    if (n > m) {
      cout << 0 << " " << m << endl;
      cout << n << " " << 0 << endl;
    } else {
      cout << n << " " << 0 << endl;
      cout << 0 << " " << m << endl;
    }
    return 0;
  }
  if (n <= m) {
    cout << n - 1 << " " << m << endl;
    cout << 0 << " " << 0 << endl;
    cout << m << " " << n << endl;
    cout << 1 << " " << 0 << endl;
  } else {
    cout << n << " " << m - 1 << endl;
    cout << 0 << " " << 0 << endl;
    cout << m << " " << n << endl;
    cout << 0 << " " << 1 << endl;
  }
}
