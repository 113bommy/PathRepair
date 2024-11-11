#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  string x, y;
  cin >> x >> y;
  long long g = gcd(x.length(), y.length()),
            l = 1ll * x.length() * y.length() / g, dist = l, c[g][26];
  for (int i = 0; i < g; i++)
    for (int j = 0; j < 26; j++) c[i][j] = 0;
  for (int i = 0; i < x.length(); i++) c[i % g][x[i] - 'a']++;
  for (int i = 0; i < y.length(); i++) dist -= c[i % g][y[i] - 'a'];
  cout << dist * x.length() * n / l << endl;
  return 0;
}
