#include <bits/stdc++.h>
using namespace std;
long long n, m, x, d;
long long ans, c[2];
int main() {
  cin >> n >> m;
  c[0] = (n / 2 + 1) * (n / 2) - (n % 2 == 0 ? n / 2 : 0);
  c[1] = n * (n - 1) / 2;
  for (int i = 0; i < m; ++i) {
    cin >> x >> d;
    ans += x * n + c[d > 0] * d;
  }
  cout.precision(12);
  cout << (double)ans / n;
  getchar();
  getchar();
  return 0;
}
