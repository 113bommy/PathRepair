#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int ad(int x, int y) { return (x + y) % mod; }
inline int mu(int x, int y) { return 1LL * x * y % mod; }
int main() {
  int n, m;
  cin >> n >> m;
  int a = 1, b = 0;
  for (int i = 0; i < n; i++) {
    int A, B;
    A = ad(mu(2 * m, a), mu(mod - n, b));
    B = ad(mu(m - 1, b), a);
    a = A, b = B;
  }
  cout << a << endl;
}
