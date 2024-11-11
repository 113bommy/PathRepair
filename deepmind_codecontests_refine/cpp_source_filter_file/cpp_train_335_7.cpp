#include <bits/stdc++.h>
using namespace std;
const long long ool = 1e18 + 9;
const int oo = 1e9 + 9, base = 1e9 + 7;
const double eps = 1e-7;
const int N = 2e6 + 6;
long long d[N][2];
void solve() {
  int n;
  cin >> n;
  cout << 4ll * max(d[n][0], d[n][1]) % base << "\n";
}
void clear() {}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 3; i <= N - 1; ++i) {
    d[i][0] = ((max(d[i - 2][1], d[i - 2][0]) * 2 % base) +
               max(d[i - 1][1], d[i - 1][0]) % base);
    d[i][0] = ((d[i - 2][0] * 2 % base) + d[i - 1][0] % base) + 1;
  }
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
    clear();
  }
  return 0;
}
