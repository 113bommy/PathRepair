#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using lli = long long int;
using iii = tuple<int, int, int>;
const int maxn = 1e6;
const int maxm = 1e7;
const int maxl = 18;
const int inf = 0x3f3f3f3f;
const lli INF = 0x3f3f3f3f3f3f3f3f;
const char sp = ' ';
const char dl = '\n';
const int mod = 1e9 + 7;
template <typename X, typename Y>
void minimize(X& a, Y b) {
  if (a > b) a = b;
  return;
}
lli n;
lli a[maxn + 5], r[4], d;
lli f[maxn + 5][4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> r[1] >> r[2] >> r[3] >> d;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(f, 0x3f, sizeof f);
  f[0][0] = -d;
  for (int i = 1; i <= n; i++) {
    minimize(f[i][0], f[i - 1][0] + d + min(r[1], r[3]) * a[i] + r[3]);
    minimize(f[i][0], f[i - 1][1] + d * 3 + r[3] + min(r[1], r[3]) * a[i] +
                          min({r[1], r[2], r[3]}));
    minimize(f[i][0], f[i - 1][1] + d * 3 + 2 * min({r[1], r[2], r[3]}) +
                          min(min(r[1], r[3]) * a[i] + r[1], r[2]));
    minimize(f[i][1],
             f[i - 1][0] + d + min(min(r[1], r[3]) * a[i] + r[1], r[2]));
    minimize(f[i][1], f[i - 1][1] + d * 3 +
                          min(min(r[1], r[3]) * a[i] + r[1], r[2]) +
                          min({r[1], r[2], r[3]}));
    if (i < n) {
      minimize(f[i][2], f[i - 1][0] + (n - i + 1) * d +
                            min(min(r[1], r[3]) * a[i] + r[1], r[2]) +
                            min({r[1], r[2], r[3]}));
      minimize(f[i][2], f[i - 1][2] + d +
                            min(min(r[1], r[3]) * a[i] + r[1], r[2]) +
                            min({r[1], r[2], r[3]}));
      minimize(f[i][2], f[i - 1][0] + (n - i + 3) * d +
                            min(min(r[1], r[3]) * a[n] + r[1], r[2]) +
                            min({r[1], r[2], r[3]}));
      minimize(f[i][2], f[i - 1][2] + 3 * d +
                            min(min(r[1], r[3]) * a[n] + r[1], r[2]) +
                            min({r[1], r[2], r[3]}));
      minimize(f[i][2], f[i - 1][2] + d + min(r[1], r[3]) * a[i] + r[3]);
    } else {
      minimize(f[i][0], f[i - 1][1] + d * 2 + r[3] + min(r[1], r[3]) * a[i] +
                            min({r[1], r[2], r[3]}));
      minimize(f[i][2],
               f[i - 1][0] + (n - i + 1) * d + min(r[1], r[3]) * a[n] + r[3]);
      minimize(f[i][2], f[i - 1][2] + d + min(r[1], r[3]) * a[n] + r[3]);
      minimize(f[i][2], f[i - 1][0] + (n - i + 3) * d +
                            min(min(r[1], r[3]) * a[n] + r[1], r[2]) +
                            min({r[1], r[2], r[3]}));
      minimize(f[i][2], f[i - 1][2] + 3 * d +
                            min(min(r[1], r[3]) * a[n] + r[1], r[2]) +
                            min({r[1], r[2], r[3]}));
    }
  }
  cout << min(f[n][0], f[n][2]);
  return 0;
}
