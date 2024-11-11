#include <bits/stdc++.h>
using namespace std;
vector<long long> a[200005];
map<long long, int> p1, p2, p3;
long long w[200005], ans, h[200005], c[200005], c1, c2;
inline long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
int cnt, tot;
int n, i, j;
int main() {
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> w[i] >> h[i] >> c[i];
    if (!p1[w[i]]) p1[w[i]] = ++cnt;
    w[i] = p1[w[i]];
    if (!p2[h[i]]) p2[h[i]] = ++tot;
    h[i] = p2[h[i]];
  }
  if (n != 1ll * cnt * tot) {
    return cout << 0, 0;
  }
  for (i = 1; i <= cnt; ++i) {
    for (j = 0; j <= tot; ++j) a[i].push_back(0);
  }
  for (i = 1; i <= n; ++i) a[w[i]][h[i]] = c[i];
  for (i = 1; i <= cnt; ++i) {
    for (j = 1; j <= tot; ++j) {
      if ((a[i][j] % 1000000007) * (a[1][1] % 1000000007) % 1000000007 !=
              (a[i][1] % 1000000007) * (a[1][j] % 1000000007) % 1000000007 ||
          (a[i][j] % 1000000009) * (a[1][1] % 1000000009) % 1000000009 !=
              (a[i][1] % 1000000009) * (a[1][j] % 1000000009) % 1000000009) {
        return cout << 0, 0;
      }
    }
  }
  for (i = 1; i <= tot; ++i) c1 = gcd(c1, a[1][i]);
  for (i = 1; i <= cnt; ++i) c2 = gcd(c2, a[i][1]);
  for (i = 1; 1ll * i * i < c1; ++i) {
    if (c1 % i == 0 && c2 % (a[1][1] / i) == 0) {
      ++ans;
    }
    if (c2 % i == 0 && c1 % (a[1][1] / i) == 0) {
      ++ans;
    }
  }
  if (1ll * i * i == c1 && c1 % i == 0 && c2 % (a[1][1] / i) == 0) ++ans;
  cout << ans;
}
