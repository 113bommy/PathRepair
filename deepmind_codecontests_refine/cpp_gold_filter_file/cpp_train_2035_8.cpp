#include <bits/stdc++.h>
using namespace std;
long long int m, n, c, d, j, k, l, r, x, t, y, u, a, b, z, i, v[10010];
int main() {
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    v[x]++;
    v[y]++;
  }
  for (i = 1; i <= n; i++) {
    c += v[i] * (v[i] - 1) / 2;
  }
  cout << c;
}
