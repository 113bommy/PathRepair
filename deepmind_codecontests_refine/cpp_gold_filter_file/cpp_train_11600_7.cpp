#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return (power(x, y / 2) * power(x, y / 2)) % mod;
  else
    return (x * ((power(x, y / 2) * power(x, y / 2)) % mod) % mod);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int x[s.size()];
  int y[s.size()];
  int z[s.size()];
  for (int i = 0; i < s.size(); i++) {
    x[i] = (i == 0 ? 0 : x[i - 1]) + (s.at(i) == 'x' ? 1 : 0);
    y[i] = (i == 0 ? 0 : y[i - 1]) + (s.at(i) == 'y' ? 1 : 0);
    z[i] = (i == 0 ? 0 : z[i - 1]) + (s.at(i) == 'z' ? 1 : 0);
  }
  int queries;
  cin >> queries;
  while (queries--) {
    int i, j;
    cin >> i >> j;
    int xS = x[j - 1] - (i == 1 ? 0 : x[i - 2]);
    int yS = y[j - 1] - (i == 1 ? 0 : y[i - 2]);
    int zS = z[j - 1] - (i == 1 ? 0 : z[i - 2]);
    int score = max({xS - min({xS, yS, zS}), yS - min({xS, yS, zS}),
                     zS - min({xS, yS, zS})});
    if (j - i <= 1 || (score <= 1)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
