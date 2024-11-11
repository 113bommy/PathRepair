#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e+9 + 7;
long long a[510], d[510][510], e[510][510];
long long E(int l, int r);
long long D(int l, int r) {
  if (d[l][r] != -1) return d[l][r];
  if (l == r + 1) {
    d[l][r] = 1;
    return 1;
  }
  long long Res = E(l, r);
  for (int i = l + 1; i <= r; i++) {
    int tmp = (E(l, i - 1) * D(i, r)) % MOD;
    Res = (Res + tmp * (a[l] < a[i])) % MOD;
  }
  d[l][r] = Res;
  return Res;
}
long long E(int l, int r) {
  if (e[l][r] != -1) return e[l][r];
  if (l == r) {
    e[l][r] = 1;
    return 1;
  }
  long long res = D(l + 1, r);
  e[l][r] = res;
  return e[l][r];
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(d, -1, 510 * 510 * 4);
  memset(e, -1, 510 * 510 * 4);
  cout << E(0, n - 1);
  return 0;
}
