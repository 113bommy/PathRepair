#include <bits/stdc++.h>
const long long MXN = 5e5 + 4;
const long long MNN = 1e3 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long OO = 1e9 + 500;
using namespace std;
long long l, r;
int main() {
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  ;
  cin >> l >> r;
  cout << "YES" << '\n';
  for (long long i = 0; i < r; i += 2) {
    cout << i + l << ' ' << l + i + 1 << '\n';
  }
  return 0;
}
