#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 7;
int mn[N];
void solve() {
  for (int i = 0; i < N; i++) mn[i] = -1;
  long long q, x, y;
  cin >> q >> x;
  long long res = 0;
  while (q--) {
    cin >> y;
    long long tmp = y % x;
    mn[tmp]++;
    if (tmp == res % x) {
      long long z = tmp;
      while (mn[z] * x + z == res) {
        res++;
        z++;
        z %= x;
      }
    }
    cout << res << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
