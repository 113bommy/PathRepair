#include <bits/stdc++.h>
long long R = 7 + 1e9, NUMTESTCASE;
const int NN = 10 + 1e6;
const double pi = acos(-1.0);
int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1},
    DI[8] = {1, 1, 0, -1, -1, -1, 0, 1}, DJ[8] = {0, 1, 1, 1, 0, -1, -1, -1};
using namespace std;
long long n, m, k, x;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (cin >> NUMTESTCASE; NUMTESTCASE; NUMTESTCASE--) {
    cin >> n >> m >> k;
    bool Ok = true;
    for (int i = (0); i <= (n - 1); ++i) {
      cin >> x;
      if (i)
        if (x >= k) {
          m = m - (x - k);
        }
      if (m < 0) Ok = false;
      m += x;
    }
    if (Ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
