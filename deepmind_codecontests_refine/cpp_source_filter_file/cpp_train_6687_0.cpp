#include <bits/stdc++.h>
using namespace std;
long long d, m;
long long power(long long no) {
  long long res = 1, x = 2;
  while (no) {
    if (no & 1) {
      res = (res * x) % m;
    }
    x = (x * x) % m;
    no = no / 2;
  }
  return res;
}
void solve() {
  cin >> d >> m;
  long long ans = 0, res = 1;
  long long rlt = 1;
  for (long long i = 0; i < 30; i++) {
    if ((power(i)) > d) break;
    rlt = (rlt * (min(power(i + 1) - 1, d) - power(i) + 2)) % m;
  }
  rlt = (rlt - 1);
  if (rlt < 0) {
    rlt += m;
  }
  cout << rlt << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
