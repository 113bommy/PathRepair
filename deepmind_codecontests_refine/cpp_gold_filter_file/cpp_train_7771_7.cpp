#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, i, j, k, l, n, m, x, y;
  cin >> n;
  long long int v[n + 8], s[n + 8];
  for (i = 0; i < n + 5; i++) v[i] = 0;
  for (i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a]++;
    v[b]++;
  }
  l = 0;
  for (i = 1; i <= n + 3; i++) {
    if (v[i] == 1) ++l;
  }
  cout << l;
}
