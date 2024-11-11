#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
long long sum, arr, ans, count;
int main() {
  long long a[1234567], b[1234567], c[1234567], k, e = 0, n, m, x = 0, y = 0,
                                                   i = 0, j = 1, t, u = 0;
  string s, q;
  cin >> n >> m >> x >> y;
  k = min(y, n % m * x);
  cout << min(n / m * y + k, x * n);
}
