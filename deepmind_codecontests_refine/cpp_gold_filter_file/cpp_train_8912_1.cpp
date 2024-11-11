#include <bits/stdc++.h>
using namespace std;
const int E = 1e6 + 5, M = 1e9 + 5;
bool asccmp(pair<int, int> x, pair<int, int> y) { return x.second < y.second; }
long long a, b, c, h[E], f[E], n, ans, z[E], o[E];
map<long long, long long> m;
string s;
int main() {
  cin >> n >> s;
  ans = 0;
  for (int q = 0; q < n; q++) {
    f[s[q] - '0']++;
    z[q] = f[0];
    o[q] = f[1];
    if (z[q] - o[q] == 0) ans = q + 1;
    if (m[z[q] - o[q]])
      ans = max(ans, q - m[z[q] - o[q]] + 1);
    else
      m[z[q] - o[q]] = q + 1;
  }
  cout << ans;
  return 0;
}
