#include <bits/stdc++.h>
using namespace std;
long long a[1001], b[1001], c[1001], k, x, e[1001], n, r, m, y, l;
string s;
long long v[100001];
long long vv[1000001];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k >> x >> r >> m;
    if (i == 0) y = k + x + r + m;
    v[i] = k + x + r + m;
  }
  sort(v, v + n);
  for (int i = (n - 1); i >= 0; i++) {
    l++;
    if (v[i] == y) return cout << l, 0;
  }
  return 0;
}
