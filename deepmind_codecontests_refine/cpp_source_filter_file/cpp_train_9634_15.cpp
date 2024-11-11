#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const long long mod = (long long)1e9 + 7;
const double eps = 1e-9;
const int inf = 100500;
int n, m, ans, stn, stm, a[7], st[7] = {1, 7, 49, 343, 2401, 16807, 117649};
bool u[7];
void rec(int x) {
  if (x == stn + stm) {
    int curm = 0, curn = 0;
    for (int i = 0; i < stm; i++) {
      curm += st[i] * a[i];
    }
    for (int i = stm; i < stn + stm; i++) {
      curn += st[i - stm] * a[i];
    }
    if (curn < n && curm < m) {
      ans++;
    }
    return;
  }
  for (int i = 0; i <= 6; i++) {
    if (!u[i]) {
      u[i] = 1;
      a[x] = i;
      rec(x + 1);
      u[i] = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int x = 1;
  while (x * 7 <= n) {
    stn++;
    x *= 7;
  }
  x = 1;
  while (x * 7 <= m) {
    stm++;
    x *= 7;
  }
  stn++;
  stm++;
  if (stn + stm > 6) {
    cout << 0;
    return 0;
  }
  rec(0);
  cout << ans;
  return 0;
}
