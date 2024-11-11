#include <bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, c, m, l, r, p, q, s;
void dihan() {
  cin >> a >> b >> c >> p >> q >> r;
  puts(a ^ p + b ^ q + c ^ r == 3 ? "NO" : "YES");
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  dihan();
}
