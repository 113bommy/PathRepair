#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, P = 110;
int n, m, p, uk;
const long double inf = 1e15;
struct line {
  long double k, b, l, r;
};
long double itrx(line a, line b) { return (a.b - b.b) / (b.k - a.k); }
vector<line> cht;
void add(long double k, long double b) {
  bool ok = true;
  while (!cht.empty() && ok) {
    if (cht.back().k == k) {
      if (cht.back().b > b)
        cht.pop_back();
      else
        return;
      continue;
    }
    long double x = itrx(cht.back(), {k, b, 0, 0});
    if (x <= cht.back().l)
      cht.pop_back();
    else
      ok = false;
  }
  while (uk >= cht.size()) uk--;
  if (!cht.empty()) {
    long double x = itrx(cht.back(), {k, b});
    cht.back().r = x;
    cht.push_back({k, b, x, inf});
  } else {
    cht.push_back({k, b, -inf, inf});
  }
  uk = max(0, uk);
}
long long d[N], pd[N], k[N], pk[N];
long long dp[N][P];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> p;
  for (int i = 1; i < n; ++i) cin >> d[i];
  for (int i = 1; i < n; ++i) pd[i] = pd[i - 1] + d[i];
  for (int i = 0; i < m; ++i) {
    int h, t;
    cin >> h >> t;
    k[i + 1] = t - pd[h - 1];
  }
  sort(k + 1, k + m + 1);
  for (int i = 1; i <= m; ++i) pk[i] = pk[i - 1] + k[i];
  for (int i = 1; i <= m; ++i) dp[0][i] = k[i] * i - pk[i];
  for (int i = 1; i < p; ++i) {
    cht.clear();
    cht.push_back({-1, 0, -inf, inf});
    uk = 0;
    for (int j = 1; j <= m; ++j) {
      while (cht[uk].r < k[j]) uk++;
      while (cht[uk].l > k[j]) uk--;
      dp[i][j] = cht[uk].k * k[j] + cht[uk].b + k[j] * (j + 1) - pk[j];
      add(-(j + 1), dp[i - 1][j] + pk[j]);
    }
  }
  cout << dp[p - 1][m];
}
