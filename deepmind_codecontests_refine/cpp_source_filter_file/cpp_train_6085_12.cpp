#include <bits/stdc++.h>
using namespace std;
int dirx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int diry[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int main() {
  int n, m, n1, m1;
  cin >> m >> n;
  n1 = n;
  m1 = m;
  if (n > m) swap(n, m);
  if (n == 0) {
    if (n1 != 0) {
      cout << m - 1 << " " << 0 << endl;
      cout << 0 << " " << 0 << endl;
      cout << m << " " << 0 << endl;
      cout << 1 << " " << 0 << endl;
    } else {
      cout << 0 << " " << m - 1 << endl;
      cout << 0 << " " << 0 << endl;
      cout << 0 << " " << m << endl;
      cout << 0 << " " << 1 << endl;
    }
  } else {
    double k1 = sqrt((double)(n * n + m * m));
    double k2 = sqrt((double)((n - 1) * (n - 1) + m * m));
    if (k1 + k2 + k2 > k1 * 2.0 + (double)(m)) {
      if (n1 < m1) {
        cout << 0 << " " << 1 << endl;
        cout << m << " " << n << endl;
        cout << 0 << " " << 0 << endl;
        cout << m << " " << n - 1 << endl;
      } else {
        cout << 1 << " " << 0 << endl;
        cout << n << " " << m << endl;
        cout << 0 << " " << 0 << endl;
        cout << n - 1 << " " << m << endl;
      }
    } else {
      if (n1 < m1) {
        cout << m << " " << n << endl;
        cout << 0 << " " << 0 << endl;
        cout << m << " " << 0 << endl;
        cout << 0 << " " << n << endl;
      } else {
        cout << n << " " << m << endl;
        cout << 0 << " " << 0 << endl;
        cout << 0 << " " << m << endl;
        cout << n << " " << 0 << endl;
      }
    }
  }
}
