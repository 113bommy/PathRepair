#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int cnt = 0;
  int kl = k * l;
  int cd = c * d;
  while (kl >= 0 && cd >= 0 && p >= 0) {
    kl = kl - nl * n;
    cd = cd - n;
    p = p - np * n;
    ++cnt;
  }
  cout << cnt - 1 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
