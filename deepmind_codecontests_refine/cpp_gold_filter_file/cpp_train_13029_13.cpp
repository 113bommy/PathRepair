#include <bits/stdc++.h>
using namespace std;
bool b[200005];
long long w[200005];
pair<int, int> f[3005][3005], g[3005][3005];
pair<int, int> sum(pair<int, int> a, pair<int, int> b) {
  long long x1 = a.first;
  long long x2 = a.second;
  long long y1 = b.first;
  long long y2 = b.second;
  return pair<int, int>((x1 * y2 + x2 * y1) % ((long long)(998244353)),
                        (x2 * y2) % ((long long)(998244353)));
}
pair<int, int> mul(pair<int, int> a, pair<int, int> b) {
  long long x1 = a.first;
  long long x2 = a.second;
  long long y1 = b.first;
  long long y2 = b.second;
  return pair<int, int>((x1 * y1) % ((long long)(998244353)),
                        (x2 * y2) % ((long long)(998244353)));
}
long long qp(long long b, long long e) {
  if (!e) return 1;
  long long x = qp(b, e / 2);
  x = (x * x) % ((long long)(998244353));
  if (e & 1) x = (x * b) % ((long long)(998244353));
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> b[i];
  long long s[2];
  s[0] = s[1] = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    s[b[i]] += w[i];
  }
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= m; j++) f[i][j] = g[i][j] = pair<int, int>(0, 1);
  for (int i = 0; i <= m; i++) f[i][m - i] = g[i][m - i] = pair<int, int>(1, 1);
  for (long long ii = m - 1; ii >= 0; ii--)
    for (long long jj = ii; jj >= 0; jj--) {
      long long j = jj, i = ii - jj;
      pair<int, int> pf1 = pair<int, int>(s[1] + i + 1, s[1] + s[0] + i - j);
      pf1.second = max(1, pf1.second);
      f[i][j] = sum(f[i][j], mul(f[i + 1][j], pf1));
      pair<int, int> pf2 = pair<int, int>(s[0] - j, s[1] + s[0] + i - j);
      pf2.second = max(1, pf1.second);
      pf2.first = max(0, pf2.first);
      f[i][j] = sum(f[i][j], mul(f[i][j + 1], pf2));
      pair<int, int> pg1 = pair<int, int>(s[1] + i, s[1] + s[0] + i - j);
      pg1.second = max(1, pg1.second);
      g[i][j] = sum(g[i][j], mul(g[i + 1][j], pg1));
      pair<int, int> pg2 = pair<int, int>(s[0] - j - 1, s[1] + s[0] + i - j);
      pg2.second = max(1, pg1.second);
      pg2.first = max(0, pg2.first);
      g[i][j] = sum(g[i][j], mul(g[i][j + 1], pg2));
    }
  for (int i = 0; i < n; i++) {
    if (b[i])
      cout << ((((w[i] * f[0][0].first) % ((long long)(998244353))) *
                qp(f[0][0].second, ((long long)(998244353)) - 2)) %
               ((long long)(998244353)))
           << '\n';
    else
      cout << ((((w[i] * g[0][0].first) % ((long long)(998244353))) *
                qp(g[0][0].second, ((long long)(998244353)) - 2)) %
               ((long long)(998244353)))
           << '\n';
  }
  return 0;
}
