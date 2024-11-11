#include <bits/stdc++.h>
using namespace std;
const int maxn = 1111;
const int N = 111111;
const double eps = 1e-10;
const double pi = acos(-1.0);
long long n, m;
long long a, b, c, d;
int k;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  if (m == 3) {
    if (n >= 5)
      cout << "-1" << endl;
    else {
      cout << "0 0" << endl;
      cout << "3 0" << endl;
      cout << "0 3" << endl;
      if (n == 4) cout << "1 1" << endl;
    }
  } else {
    for (int i = 1; i <= m; ++i) cout << i << " " << 10 + i * i << endl;
    m = n - m;
    for (int i = 1; i <= m; ++i) cout << i << " " << -10 - i * i << endl;
  }
  return 0;
}
